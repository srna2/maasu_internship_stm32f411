=====================================================
Defining Initial Code for GPIO Firmware by Amina Srna
=====================================================

Overview
========

This document summarizes the key lessons learned and insights gained from the recent tasks involving GPIO functionalities in the STM32 project.

Rebasing from Main Branch
=========================

- **Rebase Process:** Learned the importance of committing changes during the rebase process to avoid conflicts and ensure the main branch is up-to-date.
- **Commit or Stash:** Committed changes when prompted to prevent overlapping issues, ensuring a clean rebase from the main branch.

GPIO Functionalities
====================

- **Makefile Integration:** Included `gpio` in the Makefile to define how the `gpio.o` object should be built from the source file.
- **Constructor and Functions:** Created a constructor and implemented all functions in `gpio.cpp` based on the comments and STM32 datasheet.
- **Pin State Reset:** Reset the state of each pin before setting it up to ensure only relevant bits are modified, guaranteeing predictable behavior.

Key Concepts and Terms
======================

- **Linker Script:** The linker script is crucial for executing code in the correct order and allocating data in memory.
- **GPIO Port Identification:** Determined which GPIO port to use in the constructor and proceeded based on that information.
- **Clock Enabling:** Enabled the clock to power the GPIO, as its default state is off to save energy.
- **Set Mode Function:** Understood the four binary states for setting the mode of a pin:
  - `00` - Input (reset state)
  - `01` - General purpose output mode
  - `10` - Alternate function mode
  - `11` - Analog mode

  These values are binary and critical when setting up the mode

- **Input Pull-up/Pull-down Resistors:** Pull-up and pull-down resistors ensure the pin has a defined logic level when no external signal is present.
- **Resetting Methods:** All methods require resetting before setting values, following a consistent pattern.

Practical Application
=====================

- **Function Calls in Main:** Called the GPIO functions in the `main` function to perform a blinking LED operation with 1000 ms delays.
- **Output Method:** Encountered an issue with the `no_write` method, which was resolved through consultation. It highlighted the importance of additional code for future project parts.

Conclusion
==========

This task provided valuable insights into GPIO functionalities, rebasing processes, and practical application of STM32 concepts. The experience enhanced understanding of critical components and their integration in embedded systems development.

