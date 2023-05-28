![ripper-gfx-watermarked-copper-atomic-logo-png](https://github.com/ArikAckerman/NuclearServer/assets/72645415/130bce0e-c0a8-4166-8596-54bf6719cd32)

# NuclearServer
NukeExplosionEffects is a C++ project that aims to simulate the effects of a nuclear explosion based on different parameters such as bomb power, weather conditions, and population density. The project utilizes various algorithms and formulas to estimate the impact of a nuclear blast on casualties, structural damage, and the need for shelters.

Features:

Calculation of blast effects: The project calculates the blast effects including fireball radius, heavy blast damage radius, radiation radius, and thermal radiation radius based on the bomb power.

Population density estimation: It utilizes external APIs such as the WorldPop API to estimate the population density of a given location based on latitude and longitude coordinates.

Casualties estimation: Using the calculated blast effects, weather conditions, and population density, the project estimates the number of fatalities and injuries caused by the nuclear explosion.

Shelter requirement calculation: The project determines the number of shelters needed based on a percentage of the affected population. The shelter count is calculated based on the estimated population affected by the blast.

Wind influence calculation: The project takes into account the wind direction and speed to adjust factors such as fire spread and structural damage. It applies specific formulas or rules to estimate the influence of wind on the explosion effects.

Usage:

Clone the repository to your local machine.
Build and compile the project using a C++ compiler.
Provide the necessary inputs such as bomb power, latitude, longitude, weather conditions, and wind information.
Run the program to calculate the explosion effects, casualties, and shelter requirements based on the provided inputs.
Please note that for the proper functionality a client program is needed.

Contributing:

Contributions to the project are welcome. If you have any suggestions, bug fixes, or improvements, feel free to fork the repository, make the necessary changes, and create a pull request.

License:

This project is licensed under the MIT License. You are free to use, modify, and distribute the code according to the terms of the license.

Disclaimer:

This project is a simulation and should not be used as a precise representation of real-world scenarios. It is for educational and illustrative purposes only. Enjoy.
