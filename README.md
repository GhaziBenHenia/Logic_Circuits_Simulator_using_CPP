# Logic Circuits Simulator using CPP

## Overview

This project is a Logic Circuits Simulator created using the C++ language. The main goal is to build a program that can simulate the behavior of logic circuits, consisting of three types of elements: Circuits, Gates, and Nodes. Each of these elements is represented by a corresponding class in C++.

## Components

### 1. Circuit

The Circuit is the main structure that holds the logic of the entire system. It is composed of Gates, connected by Nodes. Additionally, the Circuit has special Nodes known as "Inputs" and "Outputs." Inputs provide input values (6 in total), and Outputs display the final results (3 in total). Other Nodes are essential for linking Gates within the Circuit.

### 2. Gates

Gates are logical elements within the Circuit. Each Gate has a name (e.g., G1 or G2), a specific number of input Nodes (1 or 2 in this case), and a single output Node. The Gate class is designed to calculate its output based on the given inputs. To accommodate different logic operations, specialized Gate classes (e.g., GateAND or GateNOT) inherit from the base Gate class and override relevant methods to ensure proper output calculation.

### 3. Nodes

Nodes represent individual points in the Circuit. Each Node has a name and a value (true or false). Some Nodes may have an undetermined value at certain times, indicated by the "already_computed" attribute, which is either true or false. The value of a Node is meaningful only if "already_computed" is true.

## Algorithm

The Circuit class contains an algorithm responsible for calculating the overall outputs of the circuit based on the specified inputs. This algorithm considers the logic defined in the Gate classes and ensures proper communication between Nodes.

## Usage

Once the logic is implemented, the system is capable of simulating circuits. To facilitate circuit creation, the project also includes a text file format that describes the structure of circuits and another format for specifying input values.

## Output File

After running the simulation, the system generates an Output text file that contains the results of the simulation. This file provides the values of the output Nodes in the Circuit, indicating the final outcome of the logic.

## Getting Started

1. Clone the repository.
2. Compile the C++ code using your preferred compiler.
3. Run the executable to simulate circuits.
4. Check the Output text file to view the results of the simulation.

## File Formats

- **Circuit Description File**: Describes the structure of circuits.
- **Input Description File**: Specifies input values for the simulation.
- **Output File**: Contains the results of the simulation.

## Example

An example of a simple logic circuit and its corresponding input values can be found in the "Logic_Circuits_Simulator_using_CPP" directory.
