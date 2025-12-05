# COMPILER-DESIGN

*COMPANY: CODETECH IT SOLUTIONS

*NAME: DIVYANSH

*INTERN ID: CT04DR1854

*DOMAIN: C PROGRAMMING

*DURATION: 4 WEEKS

*MENTOR: NEELA SANTOSH

#ABOUT TASK 3:- 
Compiler Designing is an important concept in computer science that focuses on converting high-level programming languages like C, Java, or Python into machine-level code that a computer can understand. A compiler takes an entire program as input and translates it into executable machine instructions. This process is essential because computers cannot directly understand human-friendly programming languages. They work only with binary codes, so a compiler works like a bridge between the programmer and the machine.

The design of a compiler is divided into several phases, each responsible for performing a different task. The first phase is Lexical Analysis, also called scanning. In this step, the compiler reads the source code character by character and groups them into meaningful units called tokens. Tokens include keywords, identifiers, operators, and symbols. For example, in the statement int a = 5;, tokens are “int”, “a”, “=”, “5”, and “;”. Lexical analysis helps remove white spaces and comments as well.

The second phase is Syntax Analysis, also known as parsing. Here the compiler checks whether the input tokens follow the grammar rules of the programming language. It builds a parse tree or syntax tree to show the structure of the program. If there is an error like a missing semicolon, incorrect bracket, or wrong structure, the parser reports it. Syntax analysis ensures the programmer wrote code in a valid format.

After syntax analysis, the compiler performs Semantic Analysis. In this phase, the compiler checks the meaning of the program. For example, whether variables are declared before use, types are matched correctly, and expressions make sense logically. Semantic analysis also performs type checking so that incompatible operations are not allowed, such as adding an integer and a string.

Next is the Intermediate Code Generation phase. The compiler converts the syntax tree into an intermediate code, which is not exactly machine code but a simplified low-level code. This makes it easier to optimize the program and also makes compilers portable for different machines.

The Optimization phase improves the intermediate code to make the program faster and reduce memory usage. This includes removing unnecessary instructions, optimizing loops, and improving the efficiency of expressions. A well-optimized program runs faster and uses fewer resources.

After optimization, the compiler enters the Code Generation phase. Here, the optimized intermediate code is converted into machine code specific to the target CPU architecture. This code is what the computer actually executes.

Finally, the Code Linking and Assembly phase combines all machine code modules together and links them with libraries to make a final executable file, such as .exe in Windows.

Compiler design also includes error handling. A good compiler provides clear and meaningful error messages to help programmers understand what went wrong in the code. Errors can be lexical, syntax, or semantic, and the compiler must detect them efficiently.

Overall, compiler designing teaches how programming languages are processed internally. It covers scanning, parsing, semantics, optimization, code generation, and linking. Understanding compiler design helps students learn how languages work internally, how memory is handled, how errors are tracked, and how performance is optimized. It is a fundamental topic in computer science and is widely used in building interpreters, virtual machines, code editors, and development tools.

#OUTPUT IMAGE:-
