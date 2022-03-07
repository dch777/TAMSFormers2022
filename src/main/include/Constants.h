// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OIConstants {
    constexpr int driverController = 0;
    constexpr int shooterController = 1;

    constexpr int LX = 0;
    constexpr int LY = 1;
    constexpr int RX = 4;
    constexpr int RY = 5;

    constexpr int A = 1;
    constexpr int B = 2;
    constexpr int X = 3;
    constexpr int Y = 4;

    constexpr int LB = 5;
    constexpr int RB = 6;
    constexpr int LT = 2;
    constexpr int RT = 3;
}

namespace IntakeConstants {
    constexpr int intakePort = 1;
    constexpr double intakeSpeed = -1.0;
}

namespace IntestineConstants {
    constexpr int intestinePorts[] = {2, 3};
    constexpr double intestineSpeeds[] = {0.3, 0.5};
}

namespace ShooterConstants {
    constexpr int shooterPort = 4;
    constexpr double shooterSpeed = 0.9;
}

namespace DriveConstants {
    constexpr int leftPorts[] = {0, 2};
    constexpr int rightPorts[] = {3, 1};
}

namespace HangerConstants {
    constexpr int rightPort = 5;
    constexpr int leftPort = 6;
}