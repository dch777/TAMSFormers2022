// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.h"
#include "subsystems/IntestineSubsystem.h"

class ActivateOuttake
    : public frc2::CommandHelper<frc2::CommandBase, ActivateOuttake> {
 public:
  explicit ActivateOuttake(IntakeSubsystem* intake, IntestineSubsystem* intestine);

  void Initialize() override;

  void End(bool interrupted) override;

 private:
  IntakeSubsystem* m_intake;
  IntestineSubsystem* m_intestines;
};