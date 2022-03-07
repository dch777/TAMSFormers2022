// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/RunCommand.h>
#include <frc2/command/StartEndCommand.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/ActivateOuttake.h"
#include "commands/ActivateIntake.h"
#include "commands/ActivateIntestines.h"
#include "commands/ActivateShooter.h"
#include "commands/SetDriveSpeed.h"
#include "commands/Auto.h"
#include "RobotContainer.h"

#include "Constants.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  m_drive.SetDefaultCommand(frc2::RunCommand(
    [this] {
      m_drive.TankDrive(m_driverController.GetRawAxis(OIConstants::RY),
                        m_driverController.GetRawAxis(OIConstants::LY));
    },
    {&m_drive}
  ));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  frc2::JoystickButton(&m_driverController, OIConstants::LB)
    .ToggleWhenPressed(new SetDriveSpeed(&m_drive, 0.5));
  frc2::JoystickButton(&m_driverController, OIConstants::RB)
    .ToggleWhenPressed(new ActivateIntake(&m_intake));
  frc2::JoystickButton(&m_driverController, OIConstants::A)
    .ToggleWhenPressed(new ActivateOuttake(&m_intake, &m_intestines));

  frc2::JoystickButton(&m_shooterController, OIConstants::X)
    .WhenHeld(new ActivateShooter(&m_shooter));
  frc2::JoystickButton(&m_shooterController, OIConstants::A)
    .WhenHeld(new ActivateIntestines(&m_intestines));
  frc2::JoystickButton(&m_shooterController, OIConstants::B)
    .WhenHeld(new frc2::StartEndCommand(
      [this] {
        m_hanger.SetSpeed(0.20);
      },
      [this] {
        m_hanger.SetSpeed(0);
      },
      {&m_hanger}
    ));
  frc2::JoystickButton(&m_shooterController, OIConstants::Y)
    .WhenHeld(new frc2::StartEndCommand(
      [this] {
        m_hanger.SetSpeed(-0.20);
      },
      [this] {
        m_hanger.SetSpeed(0);
      },
      {&m_hanger}
    ));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return new Auto(&m_drive, &m_intake, &m_intestines, &m_shooter);
}
