// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>

#include "Constants.h"

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  
  void TankDrive(double lStick, double rStick);
  void ArcadeDrive(double speed, double angle);
  void SetMaxOutput(double maxOutput);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  double m_maxOutput = 0.9;

  frc::Spark m_left1;
  frc::Spark m_left2;
  frc::MotorControllerGroup m_left{m_left1, m_left2};

  frc::Spark m_right1;
  frc::Spark m_right2;
  frc::MotorControllerGroup m_right{m_right1, m_right2};

  frc::DifferentialDrive m_drive{m_left, m_right};
};
