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
* [Diagrams](#Diagrams)
* [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Authors](#authors)
* [Acknowledgements](#acknowledgements)

## About The Project

The program presents my approach to designing software for a garden shop. It's the biggest and most complex project I've done entirely by myself and one of the biggest ever. I know that the interface is not the most beautiful, but in this project my task was to focus as much as possible on learning and using object-oriented design paradigms. Personally, I am very satisfied with dividing the project into subfolders, which significantly improves readability.

Folders and their meaning (in the software itself):

*model - data model classes
*repositories - archival classes
*managers - class of managers and only with their help the interface is operated, which significantly affects security
*exceptions - my own exception handling classes
*predicate - class predicates helpful in searching repositories

Everything in the program happens with the help of managers, which increases the security of the program and largely makes the program immune to improper behavior in the interface (sometimes by throwing an appropriate exception).

What I learned during the project:

* object-oriented programming
* templates
* predicates
* typedefs
* git using
* simple CMake building
* operator overloading
* lambda functions

What caused the most trouble:

* at first I was overwhelmed with so much new material to learn
* understanding the idea of predicates
* It was a lot of fun with pointers and references and using them correctly, especially in manager classes

A list of commonly used resources that I find helpful are listed in the acknowledgements.

## Diagrams

## Built With

The program is written in C++ using CMake. I did it on a linux system (debian 64 bit). I used the CLion environment from Jet Brains. I was originally doing this project on a different repository. The Boost Test library was used to perform unit tests. The program uses interesting solutions like vector instead of ordinary arrays or shared pointers instead of ordinary pointers. Templates are also used to help make the code more universal. The project is divided into multiple folders for easy viewing and further expansion. The project includes all object-oriented programming paradigms. The documentation was entirely handmade by me and in every function except for the interface.

## Getting Started

These simple instructions will help you download and run the program.

### Prerequisites

Download the C and C++ compiler

* gcc

* g++

Download CLion (development environment)

* [CLion](https://www.jetbrains.com/clion/download/)


### Installation

1. Clone the repo

```sh
git clone https://github.com/GoldenKacper/Garden-Shop.git
```

2. Open CLion and open the repo

3. Add a new configuration

4. Run the program


## Usage

The program is not very complicated to use and is well described, so follow the instructions and you should not have any problems.

_For an example of how the program works, see [tutorials](https://github.com/GoldenKacper/Garden-Shop/tree/main/viedos)_

## Roadmap

See the [open issues](https://github.com/GoldenKacper/Garden-Shop/issues) for a list of proposed features (and known issues).

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.
* If you have suggestions for adding or removing projects, feel free to [open an issue](https://github.com/GoldenKacper/Garden-Shop/issues/new) to discuss it, or directly create a pull request after you edit the *README.md* file with necessary changes.
* Please make sure you check your spelling and grammar.
* Create individual PR for each suggestion.
* Please also read through the [Code Of Conduct](https://github.com/GoldenKacper/Garden-Shop/blob/main/CODE_OF_CONDUCT.md) before posting your first idea as well.

### Creating A Pull Request

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature`)
3. Commit your Changes (`git commit -m 'Add some Feature'`)
4. Push to the Branch (`git push origin feature`)
5. Open a Pull Request

## License

Distributed under the Creative Commons License. See [LICENSE](https://github.com/GoldenKacper/Garden-Shop/blob/main/LICENSE.md) for more information.

## Authors

* **Kacper Jagodziński** - *student of applied computer science at the Lodz University of Technology* - [GoldenKacper](https://github.com/GoldenKacper) - *Built Garden Shop Software*

## Acknowledgements

* [Git](https://git-scm.com/docs/gittutorial)
* [Wikipedia](https://en.wikipedia.org/wiki/Object-oriented_programming)
* [W3School](https://www.w3schools.com/cpp/default.asp)
* [GeeksForGeeks](https://www.geeksforgeeks.org/templates-cpp/)

