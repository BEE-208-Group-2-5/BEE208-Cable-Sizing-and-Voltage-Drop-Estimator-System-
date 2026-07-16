\# Project Report



\## 1. Project Title

\*\*Cable Sizing and Voltage Drop Estimator System\*\*



\## 2. Group Members and Index Numbers



|**GROUP MEMBERS**|**INDEX NUMBERS**|
|-|-|
|Acquah Emmanuel Blessedman|01243816B|
|Albert Anyigba|01245225B|
|David Quartey|01245066B|
|Duke Ekow Essuman Mensah|01246738B|
|Tweneboah Theresa|01242880B|
|Owusu Tawiah Seth|01241171B|
|Korto John|01242895B|
|Ahiati Makafui|01244182B|
|Samuel Yaw Baidoo|01244456B|
|Boakye-Gyan Andrews|01246266B|





\## 3. Introduction

This project involves developing a C++ application that helps electrical technicians and students estimate cable sizes and voltage drops for electrical installations. The system calculates load current, recommends appropriate cable sizes based on current ranges, calculates voltage drop, and generates an advisory report.



\## 4. Problem Statement

Many beginner technicians and students know the power rating of an appliance but may not immediately know the current drawn or whether a selected cable is suitable. Choosing cables without calculation can lead to overheating, nuisance tripping, voltage drop, or unsafe installation. A simple C++ application is needed to address this issue.



\## 5. Aim and Objectives



\### Aim

To develop a C++ Cable Sizing and Voltage Drop Estimator System.



\### Objectives

&#x09;- Identify input, processing, and output requirements

&#x09;- Write an algorithm for the application

&#x09;- Write pseudocode for the application

&#x09;- Design a flowchart showing system logic

&#x09;- Develop a working C++ program using functions and classes

&#x09;- Use conditional statements for cable recommendation

&#x09;- Use loops for multiple load records

&#x09;- Calculate approximate voltage drop

&#x09;- Validate input values

&#x09;- Document the project using Markdown



\## 6. System Requirements

&#x09;- C++ compiler (g++, MinGW, or Visual Studio)

&#x09;- Operating System: Windows/Linux/macOS

&#x09;- GitHub account for submission



\## 7. Algorithm

\[See algorithm.md]



\## 8. Pseudocode

\[See pseudocode.md]



\## 9. Flowchart

\[See flowchart.png]



\## 10. Explanation of C++ Implementation



\### Class Design

The program uses a `CableEstimator` class with:

&#x09;- \*\*Private members\*\*: loadName, supplyVoltage, loadPower, cableLength, voltageDropFactor, loadCurrent, 	  voltageDrop, recommendedCable, advisoryMessage, vdStatus

&#x09;- \*\*Public methods\*\*: setLoadDetails(), validateDetails(), calculateCurrent(), calculateVoltageDrop(), 	 	  recommendCableSize(), displayReport(), saveReportToFile()



\### Key Features

&#x20;	\*\*Input Validation\*\*: All numeric inputs are validated to ensure positive values.

&#x20;	\*\*Loops\*\*: A `for` loop processes multiple circuits.

&#x20;	\*\*Conditionals\*\*: `if-else if-else` statements determine cable size and voltage drop status.

&#x20;	\*\*File I/O\*\*: Reports are saved to `cable\\\\\\\_sizing\\\\\\\_report.txt`.

&#x09;\*\*OOP\*\*: The `CableEstimator` class encapsulates all functionality.



\### Formula Used

&#x09;- Load Current = Power / Voltage

&#x09;- Voltage Drop = Current × Cable Length × Voltage Drop Factor

&#x09;- Acceptable limit: 4% of supply voltage



\## 11. Sample Input and Output



\### Input

\### Output



\## 12. Screenshots





\## 13. Challenges faced.

&#x09;- Input validation and clearing input buffer

&#x20;	- Handling edge cases like zero values

&#x20;	- File I/O error handling

&#x20;	- Formatting output for readability



\## 14. Individual contributions

&#x09;\[See group-contribution.md]



\## 15. Conclusion.

The Cable Sizing and Voltage Drop Estimator System successfully demonstrates the application of C++ programming concepts including classes, functions, loops, conditionals, and file I/O. The system provides a practical tool for electrical estimation and serves as a strong foundation for further development.



\## 16. Future improvements.

&#x09;- Add graphical user interface (GUI)

&#x09;- Include more cable size categories

&#x09;- Support multiple voltage systems (single-phase, three-phase)

&#x09;- Add temperature derating factors

&#x09;- Generate PDF reports

&#x09;- Add database of cable specifications

