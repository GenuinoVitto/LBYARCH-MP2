# LBYARCH-S12-MP2  
Members: <br />- Cruz, Mia Bernice<br />- Genuino, Jose Mari Victorio

This is a course requirement for Laboratory Computer Architecture

## Specifications:

Write the kernel in (1) C program and (2) an x86-64 assembly language.  The kernel is to perform a dot product between vector A and vector B and place the result in sdot.

* Required to use functional scalar SIMD registers

* Required to use functional scalar SIMD floating-point instructions

## Input: 
Scalar variable n (integer) contains the length of the vector;  Vectors A and B are both single-precision float. Scalar sdot is a single-precision float.

![image](https://github.com/GenuinoVitto/LBYARCH-MP2/assets/118496929/3b5794c0-0099-4b71-aa46-b635ed808947)

## Output: 

 **1. C Dot Product Function:**
 - For N = 2^20:
	 - Average Execution Time: **0.0171467 seconds**
 - For N = 2^24:
	 - Average Execution Time: **0.271800 seconds**

 **2. x86_64 Dot Product Function:**
 - For N = 2^20:
	 - Average Execution Time: ****0.002900 seconds****
 - For N = 2^24:
	 - Average Execution Time: ****0.053733 seconds****

**Analysis**
The x86_64 implementation outperforms the C implementation for both tests.

 - For N = 2^20, x86_64 is approximately ***6.02 times faster*** than C
 - For N = 2^24, x86_64 is approximately ***5.06 times faster*** than C

This shows that the x86_64 implementation is a better choice since it is optimized and more efficient than the C implementation.

![image](https://github.com/GenuinoVitto/LBYARCH-MP2/assets/118496929/1eb76e3e-3bc6-406e-bcd2-ccf4b2169359)


## Program was run on Visual Studio 2022
