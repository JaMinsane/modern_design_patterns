# Factories

#### Factory: A component responsible solely for the wholesale (not piecewise) creation of objects.

This section includes two design patterns that are related to the creation of objects: 
 * The Factory Method
 * The Abstract Factory

Actually, the pattern should be called "Factory Pattern" but to follow the original book of GoF, we will discuss them separately.

## Motivation to use Factories

* Object creation logic becomes too convoluted.
* Constructor is not descriptive:
	* Name mandated by name of containing type
	* Cannot overload with same sets of arguments with different names
	* Can turn into 'optional parameter hell'
* Object creation (non-piecewise, unlike Builder) can be outsourced to:
	* A separate method (Factory Method)
	* That may exist in a separate class (Factory)
	* Can create hierarchy of factories with Abstract Factory
