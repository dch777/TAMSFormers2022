// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/GenericHID.h>

#include "subsystems/DriveSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/IntestineSubsystem.h"
#include "subsystems/ShooterSubsystem.h"
#include "subsystems/HangerSubsystem.h"

#include "Constants.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  DriveSubsystem m_drive;
  IntakeSubsystem m_intake;
  IntestineSubsystem m_intestines;
  ShooterSubsystem m_shooter;
  HangerSubsystem m_hanger;

  frc::GenericHID m_driverController{OIConstants::driverController};
  frc::GenericHID m_shooterController{OIConstants::shooterController};

  void ConfigureButtonBindings();
};
