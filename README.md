# PL/0 Lexical Analyzer

## Description
This is a simple lexical analyzer for the programming language PL/0.
The program reads in a source program written in PL/0, identifies tokens, and produces an output that includes the source program, the source program lexeme table, and the token list.

## Features
- Supports tokens for identifiers, numbers, and symbols specified in the PL/0 language.
- Handles keywords such as `begin`, `end`, `if`, `while`, etc.
- Detects lexical errors such as identifier or number length exceeding the maximum allowed, and invalid symbols.
- Ignores comments and invisible characters in the input file.

## Usage
1. Compile the program using a C compiler.
2. Run the compiled executable, providing the input file containing the PL/0 source code.
3. The program will generate the token list as output.

## Input Format
The input file should contain the PL/0 source code.
Compile with gcc lex.c
./a.out input.txt

