# Inheritance - Base Types and Polymorphism
* Implement a base class Animal.  Derive classes Reptile, Mammal, and Insect from the base class.  In the base class, develop a virtual function

```cpp
void Animal::eat()
{
   std::cout << "Animal is eating" << std::endl;
}
```

* Write the class definitions, the constructors, and a virtual function for void eat() for each of the 3 subclasses.  Create dynamic instances of the 3 different subtypes and put references to the object instances in a vector.    Iterate through the vector and call the eat function for the different object instances.  If you did this correctly, using a virtual method, then the correct eat method will be called.  Call the vector variable zoo, then iterate over the zoo.

> example:
```cpp
std::vector<Animal *> zoo;
// fill the zoo vector with pointers of animal base type

for(Animal* animal : zooA)
{
     animal->eat();
}
```

If you created 3 Animals and they were Insect, Mammal and Reptile, then the output would be:

```
The Mammal eats
The Insect eats
The Reptile eats
```