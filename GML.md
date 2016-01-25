# Introduction #

Game Maker Language (GML) is a dynamically typed interpreted programming language employed by [Game Maker](GameMaker.md). GiiMote is designed to expand the GML language to support the [Wii Remote](WiiRemote.md).


# Syntax #

GML is similar in syntax to languages in the C family, Pascal, and other curly-brace languages. Unlike many languages, however, it has a very loose syntax which does not strictly require curly braces or semicolons. For instance, the following two snippets of code are equivalent:
```
/* This code: */
if (a == b && c != 2)
{
   a = 5;
}

// and this code are the same!
if a = b and not c = 2 then a := 5
```
GML does, however, distinguish between expressions and statements. For example, `c >= 1;` is not a valid statement and will cause GM to return an error. Variable assignment on the other hand is always a statement and can not be used within an expression. So the following statement will not conclude with "b" equal to 5 as it would in C++:
```
b = 6;
// Set b equal to 5
// if a is equal to 5
if (a == (b = 5)) { /* Do something */ }
```
because GML interprets it as:
```
b = 6;
// If a is equal to 0 (because b != 5)
if (a == (b == 5)) { /* Do something */ }
```
As you can see the "=" operator is a boolean-comparison operator in comparisons (so for instance `a = b = 5;` is the same as `a = b == 5;`) and an assignment operator in statements. The "==" operator on the other hand is always a comparison operator.


## Variables ##

Variables in GML do not normally need to be declared and are created the first time a value is assigned to them. They can optionally be auto-declared to 0 if used in expressions, however, this is unwise and a very poor programming practice. The exception is variables local to the current code-block which must be declared using the keyword "**var**".


### Memory Allocation and Typing ###

Variables in GML are dynamically typed and memory is allocated as it is needed. This means that the following statement is valid:
```
a = 5;
a = "Ready for the game?";
a = "I hope Georgia Tech beats UGA! (I wish...)";
```
GML supports two types: strings, and real numbers:
  * Strings are sets of ASCII characters and may be of any length.
  * Real values are implemented as signed floating point numbers and may be expressed in decimal or hexadecimal (via the '$' prefix).


### Scope ###


GML has three main variable scopes.
  * **Global variables** are declared globally for all objects and are accessed via the prefix "global."
  * **Local variables** which may be declared local to the current instance and do not require a prefix (but which may use the optional prefix "**local.**" where naming conflicts arise)
  * and a second type of **local variable** which is declared local to the current code block and must be declared using the "**var**" keyword.
Global variables may also be created using the "**globalvar**" prefix. For example:
```
globalvar a, b, c;
```
When initialized this way one does not need to use the "**global.**" prefix.
To access local variables outside of the current instance one may precede the variable with the instance ID or object name of the instance, for example:
```
object0.a = 5;
(100001).b = 2;
```
Because there is no method for manually releasing variables in Game Maker it is advisable to stay away from global variables as they are not released until the game ends. Local variables are released when their instance is destroyed or when their native control block ends.


## Resources ##

GML has no pointer type so each resource is given a unique ID which can be referenced from within various GML functions. Each instance of an object in GML contains several built-in constants which contain the values of the various resource IDs attributed to it. These include:
  * `id` - The ID of the current instance
  * `object_index` - The index of the object the instance is an instance of


# Links #

  * [GML Reference at GMLScripts.com](http://gmlscripts.com/gml/game_maker_language)