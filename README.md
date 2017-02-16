# Yunino

Repository for my Arduino Yun scripts

### TrafficLight

Simple sketch that simulates traffic lights ran sequentially (which essentially means that there's one **GREEN** traffic light at any given time).

A good starting point is to look into `constants.h` that contains variables that could be changed to alter the simulation behaviour.

Traffic lights behave similarly to a real life:
  - When there is switch from **RED** to **YELLOW**, both these lights light simultaneously.
  - Switching cycle takes the same time both ways (**YELLOW** is displayed always for the same time).
  - Length of the **GREEN** cycle could be adjusted. **RED** cycle takes the rest of the remaining time.

The simplest use case is standard crossroads with two roads intersecting or any other centrally symmetric crossroads (e.g. three roads on a triangle plan).
