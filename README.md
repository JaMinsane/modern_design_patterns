# Design Patterns

## Gamma Categorization

* This is called  *Gamma Categorization* after Erich Gamma, one of the Gang of Four authors (GoF): Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides.
* Desing Patterns are typically split into three categories:
	* **Creational Patterns**: 
		* Deal with object creation (construction) of objects.
		* Explicit (Constructor) vs. implicit (Dependency Injection Framework (DI), Reflection, etc.).
		* Wholesale (single statement) vs. piecewise (step-by-step).
	* **Structural Patterns**:
		* Concerd with the structure (e.g., class members).
		* Many patterns are wrappers that mimic the underlying class' interface.
		* Stress the importance of good API design.
	* **Behavioral Patterns**: Characterize the ways in which classes or objects interact and distribute responsibility.

### What Patterns Does This Course Cover?

This course covers all the GoF design patterns. Here's the full list of what is covered:

* SOLID Design Principles: 
	* Single Responsibility Principle:
		* A class should have one, and only one, reason to change.
		* Separation of concerns: different classes handling different, independent tasks/problems.
	* Open-Closed Principle:
		* Classes should be open for extension but closed for modification.
	* Liskov Substitution Principle:
		* You should be able to substitute a base type for a subtype.
	* Interface Segregation Principle:
		* Don't put too much into an interface; split into separate interfaces.
		* YAGNI - You Ain't Going to Need It.
	* Dependency Inversion Principle:
		* High-level modules should not depend upon low-level ones. Use abstractions.

* Creational Design Patterns: Builder, Factories (Factory Method and Abstract Factory), Prototype and Singleton
* Structrural Design Patterns: Adapter, Bridge, Composite, Decorator, Façade, Flyweight and Proxy
* Behavioral Design Patterns: Chain of Responsibility, Command, Interpreter, Iterator, Mediator, Memento, Null Object, Observer, State, Strategy, Template Method and Visitor