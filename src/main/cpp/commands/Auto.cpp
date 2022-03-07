// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/ParallelCommandGroup.h>

#include "commands/Auto.h"
#include "commands/Drive.h"
#include "commands/ActivateIntestines.h"
#include "commands/ActivateIntake.h"
#include "commands/ActivateShooter.h"
#include "Constants.h"

Auto::Auto(DriveSubsystem* drive, IntakeSubsystem* intake, 
    IntestineSubsystem* intestines, ShooterSubsystem* shooter) {
    AddCommands(
        Drive(drive, -0.7, -0.7).WithTimeout(1.0_s),
        ActivateShooter(shooter).WithTimeout(0.5_s),
        frc2::ParallelCommandGroup(
            ActivateShooter(shooter),
            ActivateIntestines(intestines)
        ).WithTimeout(1.5_s),
        frc2::ParallelCommandGroup(
            Drive(drive, -0.7, -0.7).WithTimeout(2.5_s),
            ActivateIntake(intake)
        ).WithTimeout(5.0_s),
        Drive(drive, 0.7, 0.7).WithTimeout(1.0_s),
        frc2::ParallelCommandGroup(
            ActivateShooter(shooter),
            ActivateIntestines(intestines)
        ).WithTimeout(2.0_s),
        Drive(drive, -0.7, -0.7).WithTimeout(1.0_s)
    );
}