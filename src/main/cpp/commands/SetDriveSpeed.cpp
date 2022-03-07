// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SetDriveSpeed.h"

SetDriveSpeed::SetDriveSpeed(DriveSubsystem* drivetrain, double driveSpeed)
    : m_drive(drivetrain), m_speed(driveSpeed) {
  AddRequirements(drivetrain);
}

void SetDriveSpeed::Initialize() {
  m_drive->SetMaxOutput(m_speed);
}

void SetDriveSpeed::End(bool interrupted) {
  m_drive->SetMaxOutput(0.9);
}