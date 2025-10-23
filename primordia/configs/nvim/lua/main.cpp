// +--------------------------------------------+
// |            CHAPTER 7: CONTROL FLOW         |
// +--------------------------------------------+

#include <iostream>

int main() {
  // When you run a program, the CPU (the brain of your computer that executes instructions)
  // starts at the top of main().
  // However, straight execution isn’t enough. What if the user enters a number but types
  // something invalid? This is where control flow statements come in.
  // They make decisions, repeat actions, jump to different parts of code, and handle unexpected situations.

  int x { 0 };

  // +--------------------------------------------+
  // |       CONDITIONAL STATEMENTS               |
  // +--------------------------------------------+

  // Note: Always use blocks { } to prevent indentation issues.
  if (x > 10) { // condition
    std::cout << x << " is greater than 10\n"; // true statement
  } else {
    std::cout << x << " isn't greater than 10\n"; // false statement
  }

  // -- if else vs if if --
  // Use if-else if you only want one condition to trigger.
  // Use multiple if statements if all conditions should run.

  if (x < 10) {
    std::cout << "its low";
  }

  if (x < 10) {
    std::cout << "hi";
  }

  // You can also flatten if statements.
  if (x < 0) {
    std::cout << x << " is negative\n";
  } else if (x <= 20) {
    std::cout << x << " is between 0 and 20\n";
  } else {
    std::cout << x << " is negative\n";
  }

  // Or even shorter using logical operators.
  if (x > 0 && y > 0)
    std::cout << "both numbers are positive\n";
  else if (x > 0 || y > 0)
    std::cout << "one of the numbers is positive\n";
  else
    std::cout << "neither number is positive\n";

  // +--------------------------------------------+
  // |        CONSTEXPR IF STATEMENTS             |
  // +--------------------------------------------+

  // Sometimes conditions can be determined before the program even starts (compile time).
  // Here, gravity is already a constexpr and known at compile time.
  // Since gravity is always 9.8, the if condition will always be true, and the else branch
  // will never run, yet the compiler still includes it — wasting time and space.

  constexpr double gravity { 9.8 };

  if (gravity == 9.8) {
    std::cout << "gravity is normal\n";
  } else {
    std::cout << "ur cooked\n";
  }

  // -- constexpr if --
  // By adding constexpr after if, you tell the compiler to evaluate the condition at compile time.
  // If true, the code inside if is compiled and the else block is removed.
  // If false, the opposite happens.
  if constexpr (gravity == 9.8) {
    std::cout << "gravity is normal\n";
  } else {
    std::cout << "we are not on earth";
  }

  /*
   * When compiled, this simplifies into:
   * constexpr double gravity { 9.8 };
   * std::cout << "gravity is normal.\n";
   * return 0;
   */

  // This is useful for optimization, skipping unnecessary code.

  // +--------------------------------------------+
  // |            SWITCH STATEMENTS               |
  // +--------------------------------------------+

  // When you need to compare one value against several possible options,
  // a long chain of if-else statements looks messy.
  // If the value matches one of the case labels, it jumps there.
  // If no match is found and there’s no default label, the entire block is skipped.
  // Note: The condition must be an integer or enum — no floats, strings, or complex types.
  // Always use break (to exit the switch) or return (to exit the function).

  int value { 3 };

  switch (value) {
    case 1:  std::cout << "one";     return;
    case 2:  std::cout << "two";     return;
    case 3:  std::cout << "three";   return;
    default: std::cout << "unknown"; return;
  }

  // Use switch for checking one expression (integer/enum).
  // Use if-else for checking ranges, multiple variables, or non-integral types.

  // -- switch fallthrough and scoping --
  // [[fallthrough]] attribute: intentionally lets execution continue to the next case.

  switch (2) {
    case 1:
      std::cout << 1 << '\n';
      break;

    case 2:
      std::cout << 2 << '\n';
      [[fallthrough]]; // intentional fallthrough

    case 3:
      std::cout << 3 << '\n';
      break;
  }

  // -- stacking case labels --
  // You can create multiple case labels that share the same code block.

  switch (c) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
      return true;
    default:
      return false;
  }

  // -- variable declaration inside switch -- 
  // Switch statements do not create their own scope — all cases share one.
  // Variables declared in one case can be "seen" in another, even if skipped.
  // Initialization (using =) can’t be skipped safely, so C++ forbids it in certain places.

  switch (1) {
    int a;        // ok: declaration before any case
    // int b{5};  // error: initialization before case labels is illegal

    case 1:
      int y;      // ok but messy: same scope for all cases
      y = 4;      // ok: just assigning
      break;

    case 2:
      // int z{4}; // error: can’t initialize if later cases exist (unsafe)
      y = 5;      // ok: y still visible here
      break;

    case 3:
      break;
  }

  // Why this happens:
  // The compiler allows jumps between case labels (like gotos).
  // If it jumps over an initialization, that variable never gets constructed → unsafe.
  // Fix: wrap each case in braces to create its own scope.

  switch (1) {
    case 1: {
      int x{4};
      std::cout << x;
      break;
    }

    case 2: {
      int y{5};
      std::cout << y;
      break;
    }

    default:
      std::cout << "default";
      break;
  }

  // - Switch has one big scope → risky to initialize vars directly.
  // - Use { } blocks inside cases when defining new vars.
  // - Safe, clean, and compiler-approved.

  // +--------------------------------------------+
  // |              GOTO STATEMENTS               |
  // +--------------------------------------------+

  // Tip: Just don’t use this.
  // Sometimes you want to skip ahead or loop back, so you can use goto — but it’s discouraged.

  double num { };

tryagain: // label

  std::cout << "enter a non-negative number";
  std::cin  >> num;

  if (num < 0.0) {
    goto tryagain; // jump back to the label
  }

  std::cout << "banana";

  // If the user enters a negative number, the program jumps back to the label and asks again.
  // Goto skips or repeats a section depending on where you tell it to jump.
  // Generally, use functions instead.

  // When goto can be useful:
  // Exiting nested loops early without ending the entire function.

  for (int i = 1; i < 5; ++i) {
    for (int j = 1; j < 5; ++j) {
      std::cout << i << " * " << j << " = " << i * j << '\n';
      if (i * j % 9 == 0) {
        std::cout << "found product divisible by 9. ending early.\n";
        goto end; // jump out of both loops
      }
    }
    std::cout << "incrementing the first factor.\n";
  }

end:
  std::cout << "and we're done.\n";

  // +--------------------------------------------+
  // |              LOOPS (MAJOR)                 |
  // +--------------------------------------------+

  int count { 1 };

  while (count <= 10) {
    std::cout << count << ' ';
    ++count;
  }

  std::cout << "done!\n";

  // Infinite loop
  while (1) {
    std::cout << "hello\n";
  }

  // Nested loops: useful for grids and tables
  int outer { 1 };
  while (outer <= 5) {
    int inner { 1 };
    while (inner <= outer) {
      std::cout << inner << ' ';
      ++inner;
    }
    std::cout << '\n';
    ++outer;
  }

  // +--------------------------------------------+
  // |           DO-WHILE STATEMENTS              |
  // +--------------------------------------------+

  int selection { };

  while (selection < 1 || selection > 2) {
    std::cout << "please make a selection: \n";
    std::cout << "1) gyat";
    std::cout << "2) sigma";
    std::cin  >> selection;
  }

  std::cout << "you selected option #" << selection << '\n';

  // Do-while always runs at least once before checking the condition.
  do {
    std::cout << "please make a selection: \n";
    std::cout << "1) gyat";
    std::cout << "2) sigma";
    std::cin  >> selection;
  } while (selection < 1 || selection > 2);

  std::cout << "you selected option #" << selection << '\n';

  // Favor while loops unless you specifically need to run at least once.

  // +--------------------------------------------+
  // |             FOR STATEMENTS                 |
  // +--------------------------------------------+

  /*
   * for (init-statement; condition; end-expression)
   *     statement;
   * init-statement - runs once at the start (usually declaring variables)
   * condition - checked before each loop
   * end-expression - runs after each iteration, usually to update the loop variable
   */

  for (int i { 1 }; i <= 10; ++i) {
    std::cout << i << '\n';
  }

  std::cout << '\n';

  // Count down:
  for (int i { 9 }; i >= 0; --i) {
    std::cout << i << '\n';
  }

  // Omitting parts of a for loop:
  int i { 0 };
  for ( ; i < 10; ) {
    std::cout << i << '\n';
    ++i;
  }

  // Using multiple variables:
  for (int x { 0 }, y { 9 }; x < 10; ++x, --y) {
    std::cout << x << ' ' << y << '\n';
  }

  // +--------------------------------------------+
  // |          BREAK & CONTINUE                  |
  // +--------------------------------------------+

  // -- break and return statements --
  // break: exits the current loop/switch
  // return: exits the entire function

  while (true) {
    char ch { };
    std::cout << "enter b to break or r to return";
    std::cin  >> ch;

    if (ch == 'b') break;
    if (ch == 'r') return 1;

    std::cout << "we broke out of the loop\n";
  }

  // -- continue statement --
  // Skips the rest of the loop body and moves to the next iteration.

  for (int count { 0 }; count < 10; ++count) {
    if ((count % 4) == 0) {
      continue;
    }
    std::cout << count << '\n';
  }

  // Be careful: using continue in while/do-while can cause infinite loops.

  int counter { 0 };
  while (counter < 10) {
    if (counter == 5) {
      continue;
    }
    std::cout << counter << '\n';
    ++counter;
  }

  // +--------------------------------------------+
  // |                HALTS                       |
  // +--------------------------------------------+

  // Sometimes, a program needs to stop running.
  // std::exit() ends your program immediately and returns a status code.
  // 0 means success.

  std::cout << 1 << '\n';
  clean();
  std::exit(0);
  std::cout << 2 << '\n'; // never runs

  // std::atexit() - registers functions to run automatically when std::exit() is called.
  std::atexit(cleanup);
  std::cout << 1 << '\n';
  std::exit(0); // cleanup runs first

  // std::quick_exit() / std::at_quick_exit() - faster but skip some cleanup steps.
  // std::abort() - ends program abnormally (no cleanup).
  // std::terminate() - called when unhandled exceptions occur; usually calls std::abort().

  // When to use halt?
  // Almost never — skips normal cleanup.
  // Prefer returning normally or using exceptions.
  // Good programs handle unexpected shutdowns safely (e.g., autosaving progress).
}


