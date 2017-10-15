# CoreWar
* [Subject](#subject)
* [Method](#method)
* [Help](#help)

Project's follow up on [Trello](https://trello.com/b/yPI1DAHV/corewar).

# Subject   :pushpin:

The Canadian mathematician [Alexander Keewatin Dewdney](https://en.wikipedia.org/wiki/Alexander_Dewdney) (author of "The Planiverse") first
introduced [Corewar](http://en.wikipedia.org/wiki/Core_War) in a series of Scientific American articles
starting in 1984.

In this game, computer programs (called "Warriors") compete in a virtual arena
for digital supremacy. Warriors are written in a simple Assembly dialect inspired
from "Redcode". 
The arena is an enclosed system, once the Warriors are loaded into memory at a random location, each one execute one instruction in turn. The goal is to cause the processes of opposing programs to terminate so the winner is the last one to have a surviving process.

## Virtual Machine

It is the *arena* where Warrior engage in combat. Obviously, the virtual machine, also know as Memory Array Redcode Simulator (*MARS*), is able to run severel processes simultaneously. 

----> (work in progress) It has a process queue for each program. They all start with one process, and new processes may be added to the queue with specific instructions.

## Assembler
This is the program that will compile our champion (.s extension) and translate it to *Bytecode* (.cor extension). This Bytecode will be directly interpreted by the Virtual Machine.


### Instructions
| OpName | OpCode  | Arg1 | Arg2 | Arg3 | Description | Carry | Cycles |
|:------:|:-------:|:----:|:----:|:----:|:-----------:|:-----:|:------:|
| **live** | *0x01*  | T_DIR | | | The instruction that allows a process to stay alive. It can also record that the player whose number is the argument is indeed alive. No argument's coding byte. Its only argument is on 4 bytes. | No | 10 |
| **ld** | *0x02*  | T_DIR or T_IND | T_REG | | Take a random argument and a registry. Load the value of the first argument in the registry. It will change the carry. | Yes | 5 |
| **st** | *0x03*  | T_REG | T_IND or T_REG | | Take a registry and a registry or an indirect and store the value of the registry toward a second argument. | Yes | 5 |
| **add** | *0x04*  | T_REG | T_REG | T_REG | Take three registries, add the first two, and place the result in the third, right before modifying the carry. | Yes | 10 |
| **sub** | *0x05*  | T_REG | T_REG | T_REG | Take three registries, substract the first two, and place the result in the third, right before modifying the carry. | Yes | 10 |
| **and** | *0x06*  | T_REG or T_DIR or T_IND | T_REG or T_IND or T_DIR | T_REG | Apply an **&** (bit-to-bit AND) over the first two arguments and store the result in a registry, which is the third argument. It will change the carry. | Yes | 6 |
| **or** | *0x07*  | T_REG or T_DIR or T_IND | T_REG or T_IND or T_DIR | T_REG | Apply an **\|** (bit-to-bit OR) over the first two arguments and store the result in a registry, which is the third argument. It will change the carry. | Yes | 6 |
| **xor** | *0x08*  | T_REG or T_DIR or T_IND | T_REG or T_IND or T_DIR | T_REG | Apply an **^** (bit-to-bit XOR) over the first two arguments and store the result in a registry, which is the third argument. It will change the carry. | No | 6 |
| **zjmp** | *0x09*  | T_DIR | | | It take an index and jump to this address if the carry is 1. | No | 20 |
| **ldi** | *0x0A*  | T_REG or T_DIR or T_IND | T_DIR or T_REG | T_REG | It use 2 indexes and 1 registry, adding the first two, treating that like an address, reading value of a registry's size and putting in the third. | No | 25 |
| **sti** | *0x0B*  | T_REG | T_REG or T_DIR or T_IND | T_DIR or T_REG | Take a registry and 2 indexes (potentially registries), add the two indexes and use this result as an address where the value of the first parameter will be copied. | No | 25 |
| **fork** | *0x0C*  | T_DIR | | | Create a new process that will inherit the different states of its father, except its PC, which will be put at (PC + (1st parameter % IDX_MOD)). | No | 800 |
| **lld** | *0x0D*  | T_DIR or T_IND | T_REG | | Same as **ld**, but without % IDX_MOD. It will change the carry. | Yes | 10 |
| **lldi** | *0x0E*  | T_REG or T_DIR or T_IND | T_DIR or T_REG | T_REG | Same as **ldi**, but does not apply any modulo to the addresses. It will change the carry. | Yes | 50 |
| **lfork** | *0x0F*  | T_DIR | | | Same as **fork** without modulo in the address. | No | 1000 |
| **aff** | *0x10*  | T_REG | | | The registry content is interpreted by the character's ASCII value to display on the standard output (% 256).  | No | 2 |

### Arguments
| Name | Sign | Binary Code | Encode |
|:----:|:----:|:-----------:|:------:|
| T_REG | **r** | 0b01 | 1 byte |
| T_DIR | **%** | 0b10 | 2 bytes or 4 bytes |
| T_IND | **%** or Value | 0b11 | 2 bytes |

### Libraries :books:
- [x] **libstr** - Contains most of the functions from *string.h* and *stdlib.h*. It is thought to be faster than naives replacements findable everywhere. It also implements a *std::string* like structure.
- [x] **libctype** - It implements every functions of *ctype.h*. It is garanted to be fast, using lookup-tables.
- [x] **liblist** - Higly inspired from [*Linux-like linked lists*](https://github.com/torvalds/linux/blob/master/include/linux/list.h). It implements a type oblivious, easy-to-use, doubly circularly list.
- [ ] **libopt** - Still not okay with the current result of this library. It is functionnal but the implementation is soft and performanceless. *Dependencies*: libstr, libctype *(description:  work in progress)*.
- [x] **libprintf** - replaces the C(89) printf. Supports : 64-bit integers, float/double, field parameters
	- *bonus* : binary and adresses conversions (%b and %a), time (%t), boolean (%k), [roman numerals](https://en.wikipedia.org/wiki/Roman_numerals) (%r). *Dependencies* : libstr, libctype.

# Help
# Credits
=======
- *[42 profile](https://profile.intra.42.fr/users/mvillemi) - [Linkedin](https://www.linkedin.com/in/mai-line-villemin-549773a5/) - [Github](https://github.com/LineChan)* - Villemin Mai Line
- *[42 profile](https://profile.intra.42.fr/users/frenaud) - [Linkedin](https://www.linkedin.com/in/f%C3%A9licien-renaud-0bb691131/) - [Github](https://github.com/Hohenfels)* - Renaud Félicien
- *[42 profile](https://profile.intra.42.fr/users/igomez) - [Linkedin](https://www.linkedin.com/in/illan-gomez-821a85b0/) - [Github](https://github.com/Zoellingam)* - Gomez Illan

