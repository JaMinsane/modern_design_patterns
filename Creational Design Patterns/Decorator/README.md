# Decorator

#### Adding behavior without altering the class itself

## Motivation:
* Want to augment an object with additional functionality
* Do not want to rewrite or alter existing code (OCP)
* Want to keep new functionality separate (SRP)
* Need to be able to interact with existing structures
* C++ gives us two options:
  * Aggregate the decorated object
  * Inherit from the decorated object

In general, facilitates the addition of behaviors to individual objects.