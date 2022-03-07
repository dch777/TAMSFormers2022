// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/DriveSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/IntestineSubsystem.h"
#include "subsystems/ShooterSubsystem.h"
#include "Constants.h"

class Auto
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, Auto> {
  public:
    Auto(DriveSubsystem* drive, IntakeSubsystem* intake, 
         IntestineSubsystem* intestines, ShooterSubsystem* shooter);
};