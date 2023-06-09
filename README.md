<br/>
<p align="center">
  <a href="https://github.com/GoldenKacper/Garden-Shop">
    <img src="images/shop-icon.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Garden Shop</h3>

  <p align="center">
    Software used to operate the garden shop
    <br/>
    <br/>
    <a href="https://github.com/GoldenKacper/Garden-Shop/tree/main/WorkShop"><strong>Explore the docs »</strong></a>
    <br/>
    <br/>
    <a href="https://github.com/GoldenKacper/Garden-Shop/tree/main/viedos">View Tutorials</a>
    .
    <a href="https://github.com/GoldenKacper/Garden-Shop/tree/main/bugReport">Report Bug</a>
    .
    <a href="https://github.com/GoldenKacper/Garden-Shop/tree/main/featureRequest">Request Feature</a>
  </p>
</p>

![Downloads](https://img.shields.io/github/downloads/GoldenKacper/Garden-Shop/total) ![Contributors](https://img.shields.io/github/contributors/GoldenKacper/Garden-Shop?color=dark-green) ![Stargazers](https://img.shields.io/github/stars/GoldenKacper/Garden-Shop?style=social)

## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Usage](#usage)
* [License](#license)
* [Authors](#authors)
* [Diagrams](#diagrams)
* [Acknowledgements](#acknowledgements)

## About The Project

The program presents my approach to designing software for a garden shop. At that time, it was the first such a large project in C++ that I made myself. Over time, I see the mistakes I made in it and in the next projects it will be better. I know that the interface is not the most beautiful, but in this project my task was to focus as much as possible on learning and using object-oriented design paradigms.

Folders and their meaning (in the software itself):

* model - data model classes
* repositories - archival classes
* managers - class of managers and only with their help the interface is operated, which significantly affects security
* exceptions - my own exception handling classes
* predicate - class predicates helpful in searching repositories

Everything in the program happens with the help of managers, which increases the security of the program and largely makes the program immune to improper behavior in the interface (sometimes by throwing an appropriate exception).

What I learned during the project:

* object-oriented programming
* templates
* predicates
* typedefs
* using git
* simple CMake building
* operator overloading
* lambda functions

What caused the most trouble:

* at first I was overwhelmed with so much new material to learn
* understanding the idea of predicates
* It was a lot of fun with pointers and references and using them correctly, especially in manager classes

A list of commonly used resources that I find helpful are listed in the acknowledgements.

## Built With

The program is written in C++ using CMake. I did it on a linux system (debian 64 bit). I used the CLion environment from Jet Brains. I was originally doing this project on a different repository. The Boost Test library was used to perform unit tests. The program uses interesting solutions like vector instead of ordinary arrays or shared pointers instead of ordinary pointers. Templates are also used to help make the code more universal. The project is divided into multiple folders for easy viewing and further expansion. The project includes all object-oriented programming paradigms. The documentation was entirely handmade by me and in every function except for the interface.


## Usage

The program is not very complicated to use and is well described, so follow the instructions and you should not have any problems.

_For an example of how the program works, see [tutorials](https://github.com/GoldenKacper/Garden-Shop/tree/main/viedos)_


## License

Distributed under the Creative Commons License. See [LICENSE](https://github.com/GoldenKacper/Garden-Shop/blob/main/LICENSE.md) for more information.

## Authors

* **Kacper Jagodziński** - *student of applied computer science at the Lodz University of Technology* - [GoldenKacper](https://github.com/GoldenKacper) - *Built Garden Shop Software*


## Diagrams

Diagrams are also as pdf: [diagrams.pdf](https://github.com/GoldenKacper/Garden-Shop/blob/main/diagram/GardenShop/GardenShop_UML_Kacper_Jagodzinski_V2.pdf)

![Diagram_1](images/diagram_1.png)
![Diagram_2](images/diagram_2.png)
![Diagram_3](images/diagram_3.png)
![Diagram_4](images/diagram_4.png)
![Diagram_5](images/diagram_5.png)
![Diagram_6](images/diagram_6.png)

## Acknowledgements

* [Git](https://git-scm.com/docs/gittutorial)
* [Wikipedia](https://en.wikipedia.org/wiki/Object-oriented_programming)
* [W3School](https://www.w3schools.com/cpp/default.asp)
* [GeeksForGeeks](https://www.geeksforgeeks.org/templates-cpp/)

