Lexical anaylzer which reads code from the user (via an input file in a Linux server) and then outputs the corresponding tokens for that file.
This information is valuable for parsing and compliation since it allows for the compiler to have information on what is being utilized by the program.

To run this file, import these files into a linux file system and run the 'make' command. This will generate a file named 'P1'.

You can then create a file using any name. For this example, I created a file named 'input' which has the following content within:

![input2](https://github.com/ThomasCholak/ParsingProject/assets/63080803/01fad7ec-b998-4a64-84e7-6344d19edae9)

You can then type './P1 input' (as per my example) and it will then analyze the file 'input' for data and create the corresponding tokens. However, this program
will work for any input file entered by the user with any contents.

Here is the output as per our input file with the corresponding files created. This is to simulate the tokens created by a compiler:

![input1](https://github.com/ThomasCholak/ParsingProject/assets/63080803/c8101721-6769-41be-8672-4ee4d3e26068)

