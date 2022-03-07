// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Drive.h"

#include "Constants.h"
using namespace ShooterConstants;

Drive::Drive(DriveSubsystem* drive, double left, double right)
    : m_drive{drive}, m_left{left}, m_right{right} {
  AddRequirements(drive);
}

void Drive::Initialize() {
  m_drive->TankDrive(m_right, m_left);
}

void Drive::Execute() {
  m_drive->TankDrive(m_right, m_left);
}

void Drive::End(bool interrupted) {
  m_drive->TankDrive(0, 0);
}