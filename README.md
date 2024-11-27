# Low Level Design Projects Archive

This repository contains the projects that I have built while learning low level design. The implementation of the projects is in C++. Along with their UML diagrams.

## Project List

- [Parking Lot](#1-parking-lot)
- [Vending Machine](#2-vending-machine)
- [Stack Overflow](#3-stack-overflow)

## 1. Parking Lot

### Requirements:

1. The parking lot should have multiple levels, each level with a certain number of parking spots.
2. The parking lot should support different types of vehicles, such as cars, motorcycles, and trucks.
3. Each parking spot should be able to accommodate a specific type of vehicle.
4. The system should assign a parking spot to a vehicle upon entry and release it when the vehicle exits.
5. The system should track the availability of parking spots and provide real-time information to customers.
6. The system should handle multiple entry and exit points and support concurrent access.

### Classes:

1. The **ParkingLot** class follows the Singleton pattern to ensure only one instance of the parking lot exists. It maintains a list of levels and provides methods to park and un-park vehicles.
2. The **Level** class represents a level in the parking lot and contains a list of parking spots. It handles parking and un-parking of vehicles within the level.
3. The **ParkingSpot** class represents an individual parking spot and tracks the availability and the parked vehicle.
4. The **Vehicle** class is an abstract base class for different types of vehicles. It is extended by Car, Motorcycle, and Truck classes.
5. The **VehicleType** enum defines the different types of vehicles supported by the parking lot.
6. Multi-threading is achieved through the use of synchronized keyword on critical sections to ensure thread safety.

### UML Diagram:

![UML Diagram](./media/ParkingLot_UML.png)

### Implementation:

- [JAVA](./JAVA/parkinglot)
- [C++](./CPP/parkinglot)

## 2. Vending Machine

### Requirements:

1. The vending machine should support multiple products with different prices and quantities.
1. The machine should accept coins and notes of different denominations.
1. The machine should dispense the selected product and return change if necessary.
1. The machine should keep track of the available products and their quantities.
1. The machine should handle multiple transactions concurrently and ensure data consistency.
1. The machine should provide an interface for restocking products and collecting money.
1. The machine should handle exceptional scenarios, such as insufficient funds or out-of-stock products.

### Classes, Interfaces and Enumerations:

1. The **Product** class represents a product in the vending machine, with properties such as name and price.
2. The **Coin** and **Note** enums represent the different denominations of coins and notes accepted by the vending machine.
3. The **Inventory** class manages the available products and their quantities in the vending machine. It uses a concurrent hash map to ensure thread safety.
4. The **VendingMachineState** interface defines the behavior of the vending machine in different states, such as idle, ready, and dispense.
5. The **IdleState**, **ReadyState**, and **DispenseState** classes implement the VendingMachineState interface and define the specific behaviors for each state.
6. The **VendingMachine** class is the main class that represents the vending machine. It follows the Singleton pattern to ensure only one instance of the vending machine exists.
7. The VendingMachine class maintains the current state, selected product, total payment, and provides methods for state transitions and payment handling.
8. The **VendingMachineDemo** class demonstrates the usage of the vending machine by adding products to the inventory, selecting products, inserting coins and notes, dispensing products, and returning change.

### UML Diagram:

![UML Diagram](./media/VendingMachine_UML.png)

### Implementation:

- [JAVA](./JAVA/vendingmachine)
- [C++](./CPP/vendingmachine)

## 3. Stack Overflow

### Requirements:

1. Users can post questions, answer questions, and comment on questions and answers.
2. Users can vote on questions and answers.
3. Questions should have tags associated with them.
4. Users can search for questions based on keywords, tags, or user profiles.
5. The system should assign reputation score to users based on their activity and the quality of their contributions.
6. The system should handle concurrent access and ensure data consistency.

### Classes, Interfaces and Enumerations

1. The User class represents a user of the Stack Overflow system, with properties such as id, username, email, and reputation.
2. The Question class represents a question posted by a user, with properties such as id, title, content, author, answers, comments, tags, votes and creation date.
3. The Answer class represents an answer to a question, with properties such as id, content, author, associated question, comments, votes and creation date.
4. The Comment class represents a comment on a question or an answer, with properties such as id, content, author, and creation date.
5. The Tag class represents a tag associated with a question, with properties such as id and name.
6. The Vote class represents vote associated with a question/answer.
7. The StackOverflow class is the main class that manages the Stack
8. Overflow system. It provides methods for creating user, posting questions, answers, and comments, voting on questions and answers, searching for questions, and retrieving questions by tags and users.
9. The StackOverflowDemo class demonstrates the usage of the Stack
10. Overflow system by creating users, posting questions and answers, voting, searching for questions, and retrieving questions by tags and users.

### UML Diagram:

![UML Diagram](./media/StackOverflow_UML.png)

### Implementation:

- [JAVA](./JAVA/stackoverflow)
