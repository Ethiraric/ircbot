/*
** PokemonDB.c for  in /home/sabour_f/rendu/ircbot/AI/src
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue May 12 12:50:08 2015 Florian SABOURIN
** Last update Tue May 12 12:50:10 2015 Florian SABOURIN
*/

#include <stdbool.h>
#include <stdlib.h>
#include "Pokemon.h"

const t_poke pokemons_db[] =
{
  // Name               PV,Atk,Def,Asp,Dsp,Spd             Types             Height Weight   CatchR Gender    	EggGroup(s)		   Eggc Friend, xpy xpgrp     pv atk def spa defspe speed	enName
  {"Oeuf",		0, 0, 0, 0, 0, 0,		None, None,		0, 0,		0, 0,	None,				0, 0, 0, Undefined,		0, 0, 0, 0, 0, 0,	"Egg"},
  {"Bulbizarre",	45, 49, 49, 65, 65, 45,		Plante, Poison,		7, 69,		45, 7,	EggGroup_Grass | EggGroup_Monster,	21, 70,	64, MediumSlow,		0, 0, 0, 1, 0, 0,	"Bulbasaur"},
  {"Herbizarre",	60, 62, 63, 80, 80, 60,		Plante, Poison,		10, 130,	45, 7,	EggGroup_Grass | EggGroup_Monster,	21, 70,	141, MediumSlow,	0, 0, 0, 1, 1, 0,	"Ivysaur"},
  {"Florizarre",	80, 82, 83, 100, 100, 80,	Plante, Poison,		20, 1000,	45, 7,	EggGroup_Grass | EggGroup_Monster,	21, 70,	208, MediumSlow,	0, 0, 0, 2, 1, 0,	"Venusaur"},
  {"Salameche",		39, 52, 43, 60, 50, 65,		Feu, None,		6, 85,		45, 7,	EggGroup_Dragon | EggGroup_Monster,	21, 70,	65, MediumSlow,		0, 0, 0, 0, 0, 1,	"Charmander"},
  {"Reptincel",		58, 64, 58, 80, 65, 80,		Feu, None,		11, 190,	45, 7,	EggGroup_Dragon | EggGroup_Monster,	21, 70,	142, MediumSlow,	0, 0, 0, 1, 0, 1,	"Charmeleon"},
  {"Dracaufeu",		78, 84, 78, 109, 85, 100,	Feu, Vol,		17, 905,	45, 7,	EggGroup_Dragon | EggGroup_Monster,	21, 70,	209, MediumSlow,	0, 0, 0, 3, 0, 0,	"Charizard"},
  {"Carapuce",		44, 48, 65, 50, 64, 43,		Eau, None,		5, 90,		45, 7,	EggGroup_Monster | EggGroup_Water1,	21, 70,	66, MediumSlow,		0, 0, 1, 0, 0, 0,	"Squirtle"},
  {"Carabaffe",		59, 63, 80, 65, 80, 58,		Eau, None,		10, 225,	45, 7,	EggGroup_Monster | EggGroup_Water1,	21, 70,	143, MediumSlow,	0, 0, 1, 0, 1, 0,	"Wartortle"},
  {"Tortank",		79, 83, 100, 85, 105, 78,	Eau, None,		16, 855,	45, 7,	EggGroup_Monster | EggGroup_Water1,	21, 70,	210, MediumSlow,	0, 0, 0, 0, 3, 0,	"Blastoise"},
  {"Chenipan",		45, 30, 35, 20, 20, 45,		Insecte, None,		3, 29,		255, 4,	EggGroup_Bug, 				11, 70,	53, MediumFast,		1, 0, 0, 0, 0, 0,	"Caterpie"},
  {"Chrysacier",	50, 20, 55, 25, 25, 30,		Insecte, None,		7, 99,		120, 4,	EggGroup_Bug, 				11, 70,	72, MediumFast,		0, 2, 0, 0, 0, 0,	"Metapod"},
  {"Papillusion",	60, 45, 50, 90, 80, 70,		Insecte, Vol,		11, 320,	45, 4,	EggGroup_Bug, 				11, 70,	160, MediumFast,	0, 0, 2, 1, 0, 0,	"Butterfree"},
  {"Aspicot",		40, 35, 30, 20, 20, 50,		Insecte, Poison,	3, 32,		255, 4,	EggGroup_Bug,				11, 70,	52, MediumFast,		0, 0, 0, 0, 0, 1,	"Weedle"},
  {"Coconfort",		45, 25, 50, 25, 25, 35,		Insecte, Poison,	6, 100,		120, 4,	EggGroup_Bug, 				11, 70,	71, MediumFast,		0, 0, 2, 0, 0, 0,	"Kakuna"},
  {"Dardargnan",	65, 90, 40, 45, 80, 75,		Insecte, Poison,	10, 295,	45, 4,	EggGroup_Bug, 				11, 70,	159, MediumFast,	0, 2, 0, 0, 1, 0,	"Beedrill"},
  {"Roucool",		40, 45, 40, 35, 35, 56,		Normal, Vol,		3, 18,		255, 4,	EggGroup_Flying,			16, 70,	55, MediumSlow,		0, 0, 0, 0, 0, 1,	"Pidgey"},
  {"Roucoups",		63, 60, 55, 50, 50, 71,		Normal, Vol,		11, 300,	120, 4,	EggGroup_Flying,			16, 70,	113, MediumSlow,	0, 0, 0, 0, 0, 2,	"Pidgeotto"},
  {"Roucarnage",	83, 80, 75, 70, 70, 101,	Normal, Vol,		15, 395,	45, 4,	EggGroup_Flying,			16, 70,	172, MediumSlow,	0, 0, 0, 0, 0, 3,	"Pidgeot"},
  {"Rattata",		30, 56, 35, 25, 35, 72,		Normal, None,		3, 35,		255, 4,	EggGroup_Field,			16, 70,	57, MediumFast,		0, 0, 0, 0, 0, 1,	"Rattata"},
  {"Rattatac",		55, 81, 60, 50, 70, 97,		Normal, None,		7, 185,		127, 4,	EggGroup_Field,			16, 70,	116, MediumFast,	0, 0, 0, 0, 0, 2,	"Raticate"},
  {"Piafabec",		40, 60, 30, 31, 31, 70,		Normal, Vol,		3, 20,		255, 4,	EggGroup_Flying,			16, 70,	58, MediumFast,		0, 0, 0, 0, 0, 1,	"Spearow"},
  {"Rapasdepic",	65, 90, 65, 61, 61, 100,	Normal, Vol,		12, 380,	90, 4,	EggGroup_Flying,			16, 70,	162, MediumFast,	0, 0, 0, 0, 0, 2,	"Fearow"},
  {"Abo",		35, 60, 44, 40, 54, 55,		Poison, None,		20, 69,		255, 4,	EggGroup_Field | EggGroup_Dragon,	21, 70,	62, MediumFast,		0, 1, 0, 0, 0, 0,	"Ekans"},
  {"Arbok",		60, 85, 69, 65, 79, 80,		Poison, None,		35, 650,	90, 4,	EggGroup_Field | EggGroup_Dragon,	21, 70,	147, MediumFast,	0, 2, 0, 0, 0, 0,	"Arbok"},
  {"Pikachu",		35, 55, 40, 50, 50, 90,		Electric, None,		4, 60,		190, 4,	EggGroup_Field | EggGroup_Fairy,	21, 70,	82, MediumFast,		0, 0, 0, 0, 0, 2,	"Pikachu"},
  {"Raichu",		60, 90, 55, 90, 80, 110,	Electric, None,		8, 300,		75, 4,	EggGroup_Field | EggGroup_Fairy,	21, 70,	122, MediumFast,	0, 0, 0, 0, 0, 3,	"Raichu"},
  {"Sablette",		50, 75, 85, 20, 30, 40,		Sol, None,		6, 120,		255, 4,	EggGroup_Field,			21, 70,	93, MediumFast,		0, 0, 1, 0, 0, 0,	"Sandshrew"},
  {"Sablaireau",	75, 100, 110, 45, 55, 65,	Sol, None,		10, 295,	90, 4,	EggGroup_Field,			21, 70,	163, MediumFast,	0, 0, 2, 0, 0, 0,	"Sandslash"},
  {"NidoranF",		55, 47, 52, 40, 40, 41,		Poison, None,		4, 70,		235, 0,	EggGroup_Monster | EggGroup_Field,	21, 70,	59, MediumSlow,		1, 0, 0, 0, 0, 0,	"NidoranF"},
  {"Nidorina",		70, 62, 67, 55, 55, 56,		Poison, None,		8, 200,		120, 0,	EggGroup_Undiscovered,			21, 70,	117, MediumSlow,	2, 0, 0, 0, 0, 0,	"Nidorina"},
  {"Nidoqueen",		90, 92, 87, 75, 85, 76,		Poison, Sol,		13, 600,	45, 0,	EggGroup_Undiscovered,			21, 70,	194, MediumSlow,	3, 0, 0, 0, 0, 0,	"Nidoqueen"},
  {"NidoranM",		46, 57, 40, 40, 40, 50,		Poison, None,		5, 90,		235, 8,	EggGroup_Monster | EggGroup_Field,	21, 70,	60, MediumSlow,		0, 1, 0, 0, 0, 0,	"NidoranM"},
  {"Nidorino",		61, 72, 57, 55, 55, 65,		Poison, None,		9, 195,		120, 8,	EggGroup_Monster | EggGroup_Field,	21, 70,	118, MediumSlow,	0, 2, 0, 0, 0, 0,	"Nidorino"},
  {"Nidoking",		81, 102, 77, 85, 75, 85,	Poison, Sol,		14, 620,	45, 8,	EggGroup_Monster | EggGroup_Field,	21, 70,	195, MediumSlow,	0, 3, 0, 0, 0, 0,	"Nidoking"},
  {"Melofee",		70, 45, 48, 60, 65, 35,		Normal, None,		6, 75,		150, 2,	EggGroup_Fairy, 			21, 140, 68, Fast,		2, 0, 0, 0, 0, 0,	"Clefairy"},
  {"Melodelfe",		95, 70, 73, 95, 90, 60,		Normal, None,		13, 400,	25, 2,	EggGroup_Fairy,			21, 140, 129, Fast,		3, 0, 0, 0, 0, 0,	"Clefable"},
  {"Goupix",		38, 41, 40, 50, 65, 65,		Feu, None,		6, 99,		190, 2,	EggGroup_Field, 			21, 70, 63, MediumFast,		0, 0, 0, 0, 0, 1,	"Vulpix"},
  {"Feunard",		73, 76, 75, 81, 100, 100,	Feu, None,		11, 199,	75, 2,	EggGroup_Field,			21, 70,	178, MediumFast,	0, 0, 0, 0, 1, 1,	"Ninetales"},
  {"Rondoudou",		115, 45, 20, 45, 25, 20,	Normal, None,		5, 55,		170, 2,	EggGroup_Fairy,			21, 70,	76, Fast,		2, 0, 0, 0, 0, 0,	"Jigglypuff"},
  {"Grodoudou",		140, 70, 45, 85, 50, 45,	Normal, None,		10, 120,	50, 2,	EggGroup_Fairy,			21, 70,	109, Fast,		3, 0, 0, 0, 0, 0,	"Wigglytuff"},
  {"Nosferapti",	40, 45, 35, 30, 40, 55,		Poison, Vol,		8, 75,		255, 4,	EggGroup_Flying,			16, 70,	54, MediumFast,		0, 0, 0, 0, 0, 1,	"Zubat"},
  {"Nosferalto",	75, 80, 70, 65, 75, 90,		Poison, Vol,		16, 550,	90, 4,	EggGroup_Flying,			16, 70,	171, MediumFast,	0, 0, 0, 0, 0, 2,	"Golbat"},
  {"Mystherbe",		45, 50, 55, 75, 65, 30,		Plante, Poison,		5, 54,		255, 4,	EggGroup_Grass,			21, 70,	78, MediumSlow,		0, 0, 0, 1, 0, 0,	"Oddish"},
  {"Ortide",		60, 65, 70, 85, 75, 40,		Plante, Poison,		8, 86,		120, 4,	EggGroup_Grass,			21, 70,	132, MediumSlow,	0, 0, 0, 2, 0, 0,	"Gloom"},
  {"Rafflesia",		75, 80, 85, 110, 90, 50,	Plante, Poison,		12, 186,	45, 4,	EggGroup_Grass,			21, 70,	184, MediumSlow,	0, 0, 0, 3, 0, 0,	"Vileplume"},
  {"Paras",		35, 70, 55, 45, 55, 25,		Insecte, Plante,	3, 54,		190, 4,	EggGroup_Grass | EggGroup_Bug,	21, 70, 70, MediumFast,		0, 1, 0, 0, 0, 0,	"Paras"},
  {"Parasect",		60, 95, 80, 60, 80, 30,		Insecte, Plante,	10, 295,	75, 4,	EggGroup_Grass | EggGroup_Bug,	21, 70, 128, MediumFast,	0, 2, 1, 0, 0, 0,	"Parasect"},
  {"Mimitoss",		60, 55, 50, 40, 55, 45,		Insecte, Poison,	10, 300,	190, 4,	EggGroup_Bug,				21, 70,	75, MediumFast,		0, 0, 0, 0, 1, 0,	"Venonat"},
  {"Aeromite",		70, 65, 60, 90, 75, 90,		Insecte, Poison,	15, 125,	75, 4,	EggGroup_Bug, 				21, 70,	138, MediumFast,	0, 0, 0, 1, 0, 1,	"Venomoth"},
  {"Taupiqueur",	10, 55, 25, 35, 45, 95,		Sol, None,		2, 8,		255, 4,	EggGroup_Field, 			21, 70,	81, MediumFast,		0, 0, 0, 0, 0, 1,	"Diglett"},
  {"Triopikeur",	35, 80, 50, 50, 70, 120,	Sol, None,		7, 333,		50, 4,	EggGroup_Field, 			21, 70,	153, MediumFast,	0, 0, 0, 0, 0, 2,	"Dugtrio"},
  {"Miaouss",		40, 45, 35, 40, 40, 90,		Normal, None,		4, 42,		255, 4,	EggGroup_Field, 			21, 70,	69, MediumFast,		0, 0, 0, 0, 0, 1,	"Meowth"},
  {"Persian",		65, 70, 60, 65, 65, 115,	Normal, None,		10, 320,	90, 4,	EggGroup_Field, 			21, 70,	148, MediumFast,	0, 0, 0, 0, 0, 2,	"Persian"},
  {"Psykokwak",		50, 52, 48, 65, 50, 55,		Eau, None,		8, 196,		190, 4,	EggGroup_Water1 | EggGroup_Field,	21, 70,	80, MediumFast,		0, 0, 0, 1, 0, 0,	"Psyduck"},
  {"Akwakwak",		80, 82, 78, 95, 80, 85,		Eau, None,		17, 766,	75, 4,	EggGroup_Water1 | EggGroup_Field,	21, 70,	174, MediumFast,	0, 0, 0, 2, 0, 0,	"Golduck"},
  {"Ferosinge",		40, 80, 35, 35, 45, 70,		Combat, None,		5, 280,		190, 4,	EggGroup_Field,			21, 70,	74, MediumFast,		0, 1, 0, 0, 0, 0,	"Mankey"},
  {"Colossinge",	65, 105, 60, 60, 70, 95,	Combat, None,		10, 320,	75, 4,	EggGroup_Field,			21, 70,	149, MediumFast,	0, 2, 0, 0, 0, 0,	"Primeape"},
  {"Caninos",		55, 70, 45, 70, 50, 60,		Feu, None,		7, 190,		190, 6,	EggGroup_Field,			21, 70,	91, Slow,		0, 1, 0, 0, 0, 0,	"Growlithe"},
  {"Arcanin",		90, 110, 80, 100, 80, 95,	Feu, None,		19, 1550,	75, 6,	EggGroup_Field,			21, 70,	213, Slow,		0, 2, 0, 0, 0, 0,	"Arcanine"},
  {"Ptitard",		40, 50, 40, 40, 40, 90,		Eau, None,		6, 124,		255, 4,	EggGroup_Water1,			21, 70,	77, MediumSlow,		0, 0, 0, 0, 0, 1,	"Poliwag"},
  {"Tetarte",		65, 65, 65, 50, 50, 90,		Eau, None,		10, 200,	120, 4,	EggGroup_Water1,			21, 70,	131, MediumSlow,	0, 0, 0, 0, 0, 2,	"Poliwhirl"},
  {"Tartard",		90, 95, 95, 70, 90, 70,		Eau, Combat,		13, 540,	45, 4,	EggGroup_Water1,			21, 70,	185, MediumSlow,	0, 0, 3, 0, 0, 0,	"Poliwrath"},
  {"Abra",		25, 20, 15, 105, 55, 90,	Psy, None,		9, 195,		200, 6,	EggGroup_Human_Like,			21, 70,	73, MediumSlow,		0, 0, 0, 1, 0, 0,	"Abra"},
  {"Kadabra",		40, 35, 30, 120, 70, 105,	Psy, None,		13, 565,	100, 6,	EggGroup_Human_Like,			21, 70,	145, MediumSlow,	0, 0, 0, 2, 0, 0,	"Kadabra"},
  {"Alakazam",		55, 50, 45, 135, 95, 120,	Psy, None,		15, 480,	50, 6,	EggGroup_Human_Like,			21, 70,	186, MediumSlow,	0, 0, 0, 3, 0, 0,	"Alakazam"},
  {"Machop",		70, 80, 50, 35, 35, 35,		Combat, None,		8, 195,		180, 6,	EggGroup_Human_Like,			21, 70,	88, MediumSlow,		0, 1, 0, 0, 0, 0,	"Machop"},
  {"Machopeur",		80, 100, 70, 50, 60, 45,	Combat, None,		15, 705,	90, 6,	EggGroup_Human_Like,			21, 70,	146, MediumSlow,	0, 2, 0, 0, 0, 0,	"Machoke"},
  {"Mackogneur",	90, 130, 80, 65, 85, 55,	Combat, None,		16, 1300,	45, 6,	EggGroup_Human_Like,			21, 70,	193, MediumSlow,	0, 3, 0, 0, 0, 0,	"Machamp"},
  {"Chetiflor",		50, 75, 35, 70, 30, 40,		Plante, Poison,		7, 40,		255, 4,	EggGroup_Grass,			21, 70,	84, MediumSlow,		0, 1, 0, 0, 0, 0,	"Bellsprout"},
  {"Boustiflor",	65, 90, 50, 85, 45, 55,		Plante, Poison,		10, 64,		120, 4,	EggGroup_Grass,			21, 70,	151, MediumSlow,	0, 2, 0, 0, 0, 0,	"Weepinbell"},
  {"Empiflor",		80, 105, 65, 100, 70, 70,	Plante, Poison,		17, 155,	45, 4,	EggGroup_Grass,			21, 70,	191, MediumSlow,	0, 3, 0, 0, 0, 0,	"Victreebel"},
  {"Tentacool",		40, 40, 35, 50, 100, 70,	Eau, Poison,		9, 455,		190, 4,	EggGroup_Water3,			21, 70,	105, Slow,		0, 0, 0, 0, 1, 0,	"Tentacool"},
  {"Tentacruel",	80, 70, 65, 80, 120, 100,	Eau, Poison,		16, 550,	60, 4,	EggGroup_Water3,			21, 70,	205, Slow,		0, 0, 0, 0, 2, 0,	"Tentacruel"},
  {"Racaillou",		40, 80, 100, 30, 30, 20,	Roche, Sol,		4, 200,		255, 4,	EggGroup_Mineral,			16, 70,	86, MediumSlow,		0, 0, 1, 0, 0, 0,	"Geodude"},
  {"Gravalanch",	55, 95, 115, 45, 45, 35,	Roche, Sol,		10, 1050,	120, 4,	EggGroup_Mineral,			16, 70,	134, MediumSlow,	0, 0, 2, 0, 0, 0,	"Graveler"},
  {"Grolem",		80, 120, 130, 55, 65, 45,	Roche, Sol,		14, 3000,	45, 4,	EggGroup_Mineral,			16, 70,	177, MediumSlow,	0, 0, 3, 0, 0, 0,	"Golem"},
  {"Ponyta",		50, 85, 55, 65, 65, 90,		Feu, None,		10, 300,	190, 4,	EggGroup_Field,			21, 70,	152, MediumFast,	0, 0, 0, 0, 0, 1,	"Ponyta"},
  {"Galopa",		65, 100, 70, 80, 80, 105,	Feu, None,		17, 950,	60, 4,	EggGroup_Field,			21, 70,	192, MediumFast,	0, 0, 0, 0, 0, 2,	"Rapidash"},
  {"Ramoloss",		90, 65, 65, 40, 40, 15,		Eau, Psy,		12, 360,	190, 4,	EggGroup_Monster | EggGroup_Water1,	21, 70,	99, MediumFast,		1, 0, 0, 0, 0, 0,	"Slowpoke"},
  {"Flagadoss",		95, 75, 110, 100, 80, 30,	Eau, Psy,		16, 785,	75, 4,	EggGroup_Monster | EggGroup_Water1,	21, 70,	164, MediumFast,	0, 0, 2, 0, 0, 0,	"Slowbro"},
  {"Magneti",		25, 35, 70, 95, 55, 45,		Electric, Acier,	3, 60,		190, 9,	EggGroup_Mineral,			21, 70,	89, MediumFast,		0, 0, 0, 1, 0, 0,	"Magnemite"},
  {"Magneton",		50, 60, 95, 120, 70, 70,	Electric, Acier,	10, 600,	60, 9,	EggGroup_Mineral,			21, 70,	161, MediumFast,	0, 0, 0, 2, 0, 0,	"Magneton"},
  {"Canarticho",	52, 65, 55, 58, 62, 60,		Normal, Vol,		8, 150,		45, 4,	EggGroup_Field | EggGroup_Flying,	21, 70,	94, MediumFast,		0, 1, 0, 0, 0, 0,	"Farfetchd"},
  {"Doduo",		35, 85, 45, 35, 35, 75,		Normal, Vol,		14, 392,	190, 4,	EggGroup_Flying,			21, 70,	96, MediumFast,		0, 1, 0, 0, 0, 0,	"Doduo"},
  {"Dodrio",		60, 110, 70, 60, 60, 100,	Normal, Vol,		18, 852,	45, 4,	EggGroup_Flying,			21, 70,	158, MediumFast,	0, 2, 0, 0, 0, 0,	"Dodrio"},
  {"Otaria",		65, 45, 55, 45, 70, 45,		Eau, None,		11, 900,	190, 4,	EggGroup_Water1 | EggGroup_Field,	21, 70,	100, MediumFast,	0, 0, 0, 0, 1, 0,	"Seel"},
  {"Lamantine",		90, 70, 80, 70, 95, 70,		Eau, Glace,		17, 1200,	75, 4,	EggGroup_Water1 | EggGroup_Field,	21, 70,	176, MediumFast,	0, 0, 0, 0, 2, 0,	"Dewgong"},
  {"Tadmorv",		80, 80, 50, 40, 50, 25,		Poison, None,		9, 300,		190, 4,	EggGroup_Amorphous,			21, 70,	90, MediumFast,		1, 0, 0, 0, 0, 0,	"Grimer"},
  {"Grotadmorv",	105, 105, 75, 65, 100, 50,	Poison, None,		12, 300,	75, 4,	EggGroup_Amorphous,			21, 70,	157, MediumFast,	1, 1, 0, 0, 0, 0,	"Muk"},
  {"Kokiyas",		30, 65, 100, 45, 25, 40,	Eau, None,		3, 40,		90, 4,	EggGroup_Water3,			21, 70,	97, Slow,		0, 0, 1, 0, 0, 0,	"Shellder"},
  {"Crustabri",		50, 95, 180, 85, 45, 70,	Eau, Glace,		15, 1325,	60, 4,	EggGroup_Water3,			21, 70,	203, Slow,		0, 0, 2, 0, 0, 0,	"Cloyster"},
  {"Fantominus",	30, 35, 30, 100, 35, 80,	Spectre, Poison,	13, 1,		190, 4,	EggGroup_Amorphous,			21, 70,	95, MediumSlow,		0, 0, 0, 1, 0, 0,	"Gastly"},
  {"Spectrum",		45, 50, 45, 115, 55, 95,	Spectre, Poison,	16, 1,		90, 4,	EggGroup_Amorphous,			21, 70,	126, MediumSlow,	0, 0, 0, 2, 0, 0,	"Haunter"},
  {"Ectoplasma",	60, 65, 60, 130, 75, 110,	Spectre, Poison,	15, 405,	45, 4,	EggGroup_Amorphous,			21, 70,	190, MediumSlow,	0, 0, 0, 3, 0, 0,	"Gengar"},
  {"Onix",		35, 45, 160, 30, 45, 70,	Roche, Sol,		88, 2100,	45, 4,	EggGroup_Mineral,			26, 70,	108, MediumFast,	0, 0, 1, 0, 0, 0,	"Onix"},
  {"Soporifik",		60, 48, 45, 43, 90, 42,		Psy, None,		10, 324,	190, 4,	EggGroup_Human_Like,			21, 70,	102, MediumFast,	0, 0, 0, 0, 1, 0,	"Drowzee"},
  {"Hypnomade",		85, 73, 70, 73, 115, 67,	Psy, None,		16, 756,	75, 4,	EggGroup_Human_Like,			21, 70,	165, MediumFast,	0, 0, 0, 0, 2, 0,	"Hypno"},
  {"Krabby",		30, 105, 90, 25, 25, 50,	Eau, None,		4, 65,		225, 4,	EggGroup_Water3,			21, 70,	115, MediumFast,	0, 1, 0, 0, 0, 0,	"Krabby"},
  {"Kraboss",		55, 130, 115, 50, 50, 75,	Eau, None,		13, 600,	60, 4,	EggGroup_Water3,			21, 70,	206, MediumFast,	0, 2, 0, 0, 0, 0,	"Kingler"},
  {"Voltorbe",		40, 30, 50, 55, 55, 100,	Electric, None,		5, 104,		190, 9,	EggGroup_Mineral,			21, 70,	103, MediumFast,	0, 0, 0, 0, 0, 1,	"Voltorb"},
  {"Electrode",		60, 50, 70, 80, 80, 140,	Electric, None,		12, 666,	60, 9,	EggGroup_Mineral,			21, 70,	150, MediumFast,	0, 0, 0, 0, 0, 2,	"Electrode"},
  {"Noeunoeuf",		60, 40, 80, 60, 45, 40,		Plante, Psy,		4, 25,		90, 4,	EggGroup_Grass,			21, 70,	98, Slow,		0, 0, 1, 0, 0, 0,	"Exeggcute"},
  {"Noadkoko",		95, 95, 85, 125, 65, 55,	Plante, Psy,		20, 1200,	45, 4,	EggGroup_Grass,			21, 70,	212, Slow,		0, 0, 0, 2, 0, 0,	"Exeggutor"},
  {"Osselait",		50, 50, 95, 40, 50, 35,		Sol, None,		4, 65,		190, 4,	EggGroup_Monster,			21, 70,	87, MediumFast,		0, 0, 1, 0, 0, 0,	"Cubone"},
  {"Ossatueur",		60, 80, 110, 50, 80, 45,	Sol, None,		10, 450,	75, 4,	EggGroup_Monster,			21, 70,	124, MediumFast,	0, 0, 2, 0, 0, 0,	"Marowak"},
  {"Kicklee",		50, 120, 53, 35, 110, 87,	Combat, None,		15, 480,	45, 8,	EggGroup_Human_Like,			26, 70,	139, MediumFast,	0, 2, 0, 0, 0, 0,	"Hitmonlee"},
  {"Tygnon",		50, 105, 79, 35, 110, 76,	Combat, None,		14, 502,	45, 8,	EggGroup_Human_Like,			26, 70,	140, MediumFast,	0, 0, 0, 0, 2, 0,	"Hitmonchan"},
  {"Excelangue",	90, 55, 75, 60, 75, 30,		Normal, None,		12, 655,	45, 4,	EggGroup_Monster,			21, 70,	127, MediumFast,	2, 0, 0, 0, 0, 0,	"Lickitung"},
  {"Smogo",		40, 65, 95, 60, 45, 35,		Poison, None,		6, 10,		90, 4,	EggGroup_Amorphous,			21, 70,	114, MediumFast,	0, 0, 1, 0, 0, 0,	"Koffing"},
  {"Smogogo",		65, 90, 120, 85, 70, 60,	Poison, None,		12, 95,		60, 4,	EggGroup_Amorphous,			21, 70,	173, MediumFast,	0, 0, 1, 0, 0, 0,	"Weezing"},
  {"Rhinocorne",	80, 85, 95, 30, 30, 25,		Sol, Roche,		10, 1150,	120, 4,	EggGroup_Monster | EggGroup_Field,	21, 70,	135, Slow,		0, 0, 1, 0, 0, 0,	"Rhyhorn"},
  {"Rhinoferos",	105, 130, 120, 45, 45, 40,	Sol, Roche,		19, 1200,	60, 4,	EggGroup_Monster | EggGroup_Field,	21, 70,	204, Slow,		0, 2, 0, 0, 0, 0,	"Rhydon"},
  {"Leveinard",		250, 5, 5, 35, 105, 50,		Normal, None,		11, 346,	30, 0,	EggGroup_Fairy,			41, 140,255, Fast,		2, 0, 0, 0, 0, 0,	"Chansey"},
  {"Saquedeneu",	65, 55, 115, 100, 40, 60,	Plante, None,		10, 350,	45, 4,	EggGroup_Grass,			21, 70,	166, MediumFast,	0, 0, 1, 0, 0, 0,	"Tangela"},
  {"Kangourex",		105, 95, 80, 40, 80, 90,	Normal, None,		22, 800,	45, 0,	EggGroup_Monster,			21, 70,	175, MediumFast,	2, 0, 0, 0, 0, 0,	"Kangaskhan"},
  {"Hypotrempe",	30, 40, 70, 70, 25, 60,		Eau, None,		4, 80,		225, 4,	EggGroup_Water1 | EggGroup_Dragon,	21, 70,	83, MediumFast,		0, 0, 0, 1, 0, 0,	"Horsea"},
  {"Hypocean",		55, 65, 95, 95, 45, 85,		Eau, None,		12, 250,	75, 4,	EggGroup_Water1 | EggGroup_Dragon,	21, 70,	155, MediumFast,	0, 0, 1, 1, 0, 0,	"Seadra"},
  {"Poissirene",	45, 67, 60, 35, 50, 63,		Eau, None,		6, 150,		225, 4,	EggGroup_Water2,			21, 70,	111, MediumFast,	0, 1, 0, 0, 0, 0,	"Goldeen"},
  {"Poissoroy",		80, 92, 65, 65, 80, 68,		Eau, None,		13, 390,	60, 4,	EggGroup_Water2,			21, 70,	170, MediumFast,	0, 2, 0, 0, 0, 0,	"Seaking"},
  {"Stari",		30, 45, 55, 70, 55, 85,		Eau, None,		8, 345,		225, 9,	EggGroup_Water3,			21, 70,	106, Slow,		0, 0, 0, 0, 0, 1,	"Staryu"},
  {"Staross",		60, 75, 85, 100, 85, 115,	Eau, Psy,		11, 800,	60, 9,	EggGroup_Water3,			21, 70,	207, Slow,		0, 0, 0, 0, 0, 2,	"Starmie"},
  {"Mr. Mime",		40, 45, 65, 100, 120, 90,	Psy, None,		13, 545,	45, 4,	EggGroup_Human_Like,			26, 70,	136, MediumFast,	0, 0, 0, 0, 2, 0,	"Mr. Mime"},
  {"Insecateur",	70, 110, 80, 55, 80, 105,	Insecte, Vol,		15, 560,	45, 4,	EggGroup_Bug,				26, 70,	187, MediumFast,	0, 1, 0, 0, 0, 0,	"Scyther"},
  {"Lippoutou",		65, 50, 35, 115, 95, 95,	Glace, Psy,		14, 406,	45, 0,	EggGroup_Human_Like,			26, 70,	137, MediumFast,	0, 0, 0, 2, 0, 0,	"Jynx"},
  {"Elektek",		65, 83, 57, 95, 85, 105,	Electric, None,		11, 300,	45, 6,	EggGroup_Human_Like,			26, 70,	156, MediumFast,	0, 0, 0, 0, 0, 2,	"Electabuzz"},
  {"Magmar",		65, 95, 57, 100, 85, 93,	Feu, None,		13, 445,	45, 6,	EggGroup_Human_Like,			26, 70,	167, MediumFast,	0, 0, 0, 2, 0, 0,	"Magmar"},
  {"Scarabrute",	65, 125, 100, 55, 70, 85,	Insecte, None,		15, 550,	45, 4,	EggGroup_Bug,				26, 70,	200, Slow,		0, 2, 0, 0, 0, 0,	"Pinsir"},
  {"Tauros",		75, 100, 95, 40, 70, 110,	Normal, None,		14, 884,	45, 8,	EggGroup_Field,			21, 70,	211, Slow,		0, 1, 0, 0, 0, 0,	"Tauros"},
  {"Magicarpe",		20, 10, 55, 15, 20, 80,		Eau, None,		9, 100,		255, 4,	EggGroup_Water2 | EggGroup_Dragon,	6, 70,	20, Slow,		0, 0, 0, 0, 0, 1,	"Magikarp"},
  {"Leviator",		95, 125, 79, 60, 100, 81,	Eau, Vol,		65, 2350,	45, 4,	EggGroup_Water2 | EggGroup_Dragon,	6, 70,	214, Slow,		0, 2, 0, 0, 0, 0,	"Gyarados"},
  {"Lokhlass",		130, 85, 80, 85, 95, 60,	Eau, Glace,		25, 2200,	45, 4,	EggGroup_Monster | EggGroup_Water1,	41, 70,	219, Slow,		2, 0, 0, 0, 0, 0,	"Lapras"},
  {"Metamorph",		48, 48, 48, 48, 48, 48,		Normal, None,		3, 40,		35, 9,	EggGroup_Ditto,			21, 70,	61, MediumFast,		1, 0, 0, 0, 0, 0,	"Ditto"},
  {"Evoli",		55, 55, 50, 45, 65, 55,		Normal, None,		3, 65,		45, 7,	EggGroup_Field,			36, 70,	92, MediumFast,		0, 0, 0, 0, 1, 0,	"Eevee"},
  {"Aquali",		130, 65, 60, 110, 95, 65,	Eau, None,		10, 290,	45, 7,	EggGroup_Field,			36, 70,	196, MediumFast,	2, 0, 0, 0, 0, 0,	"Vaporeon"},
  {"Voltali",		65, 65, 60, 110, 95, 130,	Electric, None,		8, 245,		45, 7,	EggGroup_Field,			36, 70,	197, MediumFast,	0, 0, 0, 0, 0, 2,	"Jolteon"},
  {"Pyroli",		65, 130, 60, 95, 110, 65,	Feu, None,		9, 250,		45, 7,	EggGroup_Field,			36, 70,	198, MediumFast,	0, 2, 0, 0, 0, 0,	"Flareon"},
  {"Porygon",		65, 60, 70, 85, 75, 40,		Normal, None,		8, 325,		45, 9,	EggGroup_Mineral,			21, 70,	130, MediumFast,	0, 0, 0, 1, 0, 0,	"Porygon"},
  {"Amonita",		35, 40, 100, 90, 55, 35,	Roche, Eau,		4, 75,		45, 7,	EggGroup_Water1 | EggGroup_Water3,	31, 70,	120, MediumFast,	0, 0, 1, 0, 0, 0,	"Omanyte"},
  {"Amonistar",		70, 60, 125, 115, 70, 55,	Roche, Eau,		10, 350,	45, 7,	EggGroup_Water1 | EggGroup_Water3,	31, 70,	199, MediumFast,	0, 0, 2, 0, 0, 0,	"Omastar"},
  {"Kabuto",		30, 80, 90, 55, 45, 55,		Roche, Eau,		5, 115,		45, 7,	EggGroup_Water1 | EggGroup_Water3,	31, 70,	119, MediumFast,	0, 0, 1, 0, 0, 0,	"Kabuto"},
  {"Kabutops",		60, 115, 105, 65, 70, 80,	Roche, Eau,		13, 405,	45, 7,	EggGroup_Water1 | EggGroup_Water3,	31, 70,	201, MediumFast,	0, 2, 0, 0, 0, 0,	"Kabutops"},
  {"Ptera",		80, 105, 65, 60, 75, 130,	Roche, Vol,		18, 590,	45, 7,	EggGroup_Flying,			31, 70,	202, Slow,		0, 0, 0, 0, 0, 2,	"Aerodactyl"},
  {"Ronflex",		160, 110, 65, 65, 110, 30,	Normal, None,		21, 4600,	25, 7,	EggGroup_Monster,			41, 70,	154, Slow,		2, 0, 0, 0, 0, 0,	"Snorlax"},
  {"Artikodin",		90, 85, 100, 95, 125, 85,	Glace, Vol,		17, 554,	3, 9,	EggGroup_Undiscovered,			81, 35,	215, Slow,		0, 0, 0, 0, 3, 0,	"Articuno"},
  {"Electhor",		90, 90, 85, 125, 90, 100,	Electric, Vol,		16, 526,	3, 9,	EggGroup_Undiscovered,			81, 35,	216, Slow,		0, 0, 0, 3, 0, 0,	"Zapdos"},
  {"Sulfura",		90, 100, 90, 125, 85, 90,	Feu, Vol,		20, 600,	3, 9,	EggGroup_Undiscovered,			81, 35,	217, Slow,		0, 0, 0, 3, 0, 0,	"Moltres"},
  {"Minidraco",		41, 64, 45, 50, 50, 50,		Dragon, None,		18, 33,		45, 4,	EggGroup_Water1 | EggGroup_Dragon,	41, 35,	67, Slow,		0, 1, 0, 0, 0, 0,	"Dratini"},
  {"Draco",		61, 84, 65, 70, 70, 70,		Dragon, None,		40, 165,	45, 4,	EggGroup_Water1 | EggGroup_Dragon,	41, 35,	144, Slow,		0, 2, 0, 0, 0, 0,	"Dragonair"},
  {"Dracolosse",	91, 134, 95, 100, 100, 80,	Dragon, Vol,		22, 2100,	45, 4,	EggGroup_Water1 | EggGroup_Dragon,	41, 35,	218, Slow,		0, 3, 0, 0, 0, 0,	"Dragonite"},
  {"Mewtwo",		106, 110, 90, 154, 90, 130,	Psy, None,		20, 1220,	3, 9,	EggGroup_Undiscovered,			121, 0,	220, Slow,		0, 0, 0, 3, 0, 0,	"Mewtwo"},
  {"Mew",		100, 100, 100, 100, 100, 100,	Psy, None,		4, 40,		45, 9,	EggGroup_Undiscovered,			41, 100, 64, Slow,		3, 0, 0, 0, 0, 0,	"Mew"},
  {"Germignon",		45, 49, 65, 49, 65, 45,		Plante, None,		9, 64,		45, 7,	EggGroup_Grass | EggGroup_Monster, 21, 70,		64, MediumSlow,		0, 0, 0, 0, 1, 0,	"Chikorita"},
  {"Macronium",		60, 62, 80, 63, 80, 60,		Plante, None,		12, 158,	45, 7,	EggGroup_Grass | EggGroup_Monster, 21, 70,		141, MediumSlow,	0, 0, 1, 0, 1, 0,	"Bayleef"},
  {"Meganium",		80, 82, 100, 83, 100, 80,	Plante, None,		18, 1005,	45, 7,	EggGroup_Grass | EggGroup_Monster, 21, 70,		208, MediumSlow,	0, 0, 1, 0, 2, 0,	"Meganium"},
  {"Hericendre",	39, 52, 43, 60, 50, 65,		Feu, None,		5, 79,		45, 7,	EggGroup_Field, 21, 70,		65, MediumSlow,		0, 0, 0, 0, 0, 1,	"Cyndaquil"},
  {"Feurisson",		58, 64, 58, 80, 65, 80,		Feu, None,		9, 190,		45, 7,	EggGroup_Field, 21, 70,		142, MediumSlow,	0, 0, 0, 1, 0, 1,	"Quilava"},
  {"Typhlosion",	78, 84, 78, 109, 85, 100,	Feu, None,		17, 795,	45, 7,	EggGroup_Field, 21, 70,		209, MediumSlow,	0, 0, 0, 3, 0, 0,	"Typhlosion"},
  {"Kaiminus",		50, 65, 64, 44, 48, 43,		Eau, None,		6, 95,		45, 7,	EggGroup_Monster | EggGroup_Water1, 21, 70,		66, MediumSlow,		0, 1, 0, 0, 0, 0,	"Totodile"},
  {"Crocrodil",		65, 80, 80, 59, 63, 58,		Eau, None,		11, 255,	45, 7,	EggGroup_Monster | EggGroup_Water1, 21, 70,		143, MediumSlow,	0, 1, 1, 0, 0, 0,	"Croconaw"},
  {"Aligatueur",	85, 105, 100, 79, 83, 78,	Eau, None,		23, 888,	45, 7,	EggGroup_Monster | EggGroup_Water1, 21, 70,		210, MediumSlow,	0, 2, 1, 0, 0, 0,	"Feraligatr"},
  {"Fouinette",		35, 46, 34, 35, 45, 20,		Normal, None,		8, 60,		255, 4,	EggGroup_Field, 16, 70,		57, MediumFast,		0, 1, 0, 0, 0, 0,	"Sentret"},
  {"Fouinar",		85, 76, 64, 45, 55, 90,		Normal, None,		18, 325,	90, 4,	EggGroup_Field, 16, 70,		116, MediumFast,	0, 0, 0, 0, 0, 2,	"Furret"},
  {"Hoothoot",		60, 30, 30, 36, 56, 50,		Normal, Vol,		7, 212,		255, 4,	EggGroup_Flying, 16, 70,		58, MediumFast,		1, 0, 0, 0, 0, 0,	"Hoothoot"},
  {"Noarfang",		100, 50, 50, 76, 96, 70,	Normal, Vol,		16, 408,	90, 4,	EggGroup_Flying, 16, 70,		162, MediumFast,	2, 0, 0, 0, 0, 0,	"Noctowl"},
  {"Coxy",		40, 20, 30, 40, 80, 55,		Insecte, Vol,		10, 108,	255, 4,	EggGroup_Bug, 16, 70,		54, Fast,		0, 0, 0, 0, 1, 0,	"Ledyba"},
  {"Coxyclaque",	55, 35, 50, 55, 110, 85,	Insecte, Vol,		14, 356,	90, 4,	EggGroup_Bug, 16, 70,		134, Fast,		0, 0, 0, 0, 2, 0,	"Ledian"},
  {"Mimigal",		40, 60, 40, 40, 40, 30,		Insecte, Poison,	5, 85,		255, 4,	EggGroup_Bug, 16, 70,		54, Fast,		0, 1, 0, 0, 0, 0,	"Spinarak"},
  {"Migalos",		70, 90, 70, 60, 60, 40,		Insecte, Poison,	11, 335,	90, 4,	EggGroup_Bug, 16, 70,		134, Fast,		0, 2, 0, 0, 0, 0,	"Ariados"},
  {"Nostenfer",		85, 90, 80, 70, 80, 130,	Poison, Vol,		18, 750,	90, 4,	EggGroup_Flying, 16, 70,		204, MediumFast,	0, 0, 0, 0, 0, 3,	"Crobat"},
  {"Loupio",		75, 38, 38, 56, 56, 67,		Eau, Electric,		5, 120,		190, 4,	EggGroup_Water2, 21, 70,		90, Slow,		1, 0, 0, 0, 0, 0,	"Chinchou"},
  {"Lanturn",		125, 58, 58, 76, 76, 67,	Eau, Electric,		12, 225,	75, 4,	EggGroup_Water2, 21, 70,		156, Slow,		2, 0, 0, 0, 0, 0,	"Lanturn"},
  {"Pichu",		20, 40, 15, 35, 35, 60,		Electric, None,		3, 20,		190, 4,	EggGroup_Undiscovered, 21, 70,		42, MediumFast,		0, 0, 0, 0, 0, 1,	"Pichu"},
  {"Melo",		50, 25, 28, 45, 55, 15,		Normal, None,		3, 30,		150, 2,	EggGroup_Undiscovered, 21, 140,	37, Fast,		0, 0, 0, 0, 1, 0,	"Cleffa"},
  {"Toudoudou",		90, 30, 15, 40, 20, 15,		Normal, None,		3, 10,		170, 2,	EggGroup_Undiscovered, 21, 70,		39, Fast,		1, 0, 0, 0, 0, 0,	"Igglybuff"},
  {"Togepi",		35, 20, 65, 40, 65, 20,		Normal, None,		3, 15,		190, 7,	EggGroup_Undiscovered, 11, 70,		74, Fast,		0, 0, 0, 0, 1, 0,	"Togepi"},
  {"Togetic",		55, 40, 85, 80, 105, 40,	Normal, Vol,		6, 32,		75, 7,	EggGroup_Flying | EggGroup_Fairy, 11, 70,		114, Fast,		0, 0, 0, 0, 2, 0,	"Togetic"},
  {"Natu",		40, 50, 45, 70, 45, 70,		Psy, Vol,		2, 20,		190, 4,	EggGroup_Flying, 21, 70,		73, MediumFast,		0, 0, 0, 1, 0, 0,	"Natu"},
  {"Xatu",		65, 75, 70, 95, 70, 95,		Psy, Vol,		15, 150,	75, 4,	EggGroup_Flying, 21, 70,		171, MediumFast,	0, 0, 0, 1, 0, 1,	"Xatu"},
  {"Wattouat",		55, 40, 40, 65, 45, 35,		Electric, None,		6, 78,		235, 4,	EggGroup_Monster | EggGroup_Field, 21, 70,		52, MediumSlow,		0, 0, 0, 1, 0, 0,	"Mareep"},
  {"Lainergie",		70, 55, 55, 80, 60, 45,		Electric, None,		8, 133,		120, 4,	EggGroup_Monster | EggGroup_Field, 21, 70,		117, MediumSlow,	0, 0, 0, 2, 0, 0,	"Flaaffy"},
  {"Pharamp",		90, 75, 85, 115, 90, 55,	Electric, None,		14, 615,	45, 4,	EggGroup_Monster | EggGroup_Field, 21, 70,		194, MediumSlow,	0, 0, 0, 3, 0, 0,	"Ampharos"},
  {"Jolifleur",		75, 80, 95, 90, 100, 50,	Plante, None,		4, 58,		45, 4,	EggGroup_Grass, 21, 70,		184, MediumSlow,	0, 0, 0, 0, 3, 0,	"Bellossom"},
  {"Marill",		70, 20, 50, 20, 50, 40,		Eau, None,		4, 96,		190, 4,	EggGroup_Water1 | EggGroup_Fairy, 11, 70,		58, Fast,		2, 0, 0, 0, 0, 0,	"Marill"},
  {"Azumarill",		100, 50, 80, 60, 80, 50,	Eau, None,		8, 285,		75, 4,	EggGroup_Water1 | EggGroup_Fairy, 11, 70,		153, Fast,		3, 0, 0, 0, 0, 0,	"Azumarill"},
  {"Simularbre",	70, 100, 115, 30, 65, 30,	Roche, None,		12, 380,	65, 4,	EggGroup_Mineral, 21, 70,		135, MediumFast,	0, 0, 2, 0, 0, 0,	"Sudowoodo"},
  {"Tarpaud",		90, 75, 75, 90, 100, 70,	Eau, None,		11, 339,	45, 4,	EggGroup_Water1, 21, 70,		185, MediumSlow,	0, 0, 0, 0, 3, 0,	"Politoed"},
  {"Granivol",		35, 35, 40, 35, 55, 50,		Plante, Vol,		4, 5,		255, 4,	EggGroup_Fairy | EggGroup_Grass, 21, 70,		74, MediumSlow,		0, 0, 0, 0, 1, 0,	"Hoppip"},
  {"Floravol",		55, 45, 50, 45, 65, 80,		Plante, Vol,		6, 10,		120, 4,	EggGroup_Fairy | EggGroup_Grass, 21, 70,		136, MediumSlow,	0, 0, 0, 0, 0, 2,	"Skiploom"},
  {"Cotovol",		75, 55, 70, 55, 95, 110,	Plante, Vol,		8, 30,		45, 4,	EggGroup_Fairy | EggGroup_Grass, 21, 70,		176, MediumSlow,	0, 0, 0, 0, 0, 3,	"Jumpluff"},
  {"Capumain",		55, 70, 55, 40, 55, 85,		Normal, None,		8, 115,		45, 4,	EggGroup_Field, 21, 70,		94, Fast,		0, 0, 0, 0, 0, 1,	"Aipom"},
  {"Tournegrin",	30, 30, 30, 30, 30, 30,		Plante, None,		3, 18,		235, 4,	EggGroup_Grass, 21, 70,		52, MediumSlow,		0, 0, 0, 1, 0, 0,	"Sunkern"},
  {"Heliatronc",	75, 75, 55, 105, 85, 30,	Plante, None,		8, 85,		120, 4,	EggGroup_Grass, 21, 70,		146, MediumSlow,	0, 0, 0, 2, 0, 0,	"Sunflora"},
  {"Yanma",		65, 65, 45, 75, 45, 95,		Insecte, Vol,		12, 380,	75, 4,	EggGroup_Bug, 21, 70,		147, MediumFast,	0, 0, 0, 0, 0, 1,	"Yanma"},
  {"Axoloto",		55, 45, 45, 25, 25, 15,		Eau, Sol,		4, 85,		255, 4,	EggGroup_Water1 | EggGroup_Field, 21, 70,		52, MediumFast,		1, 0, 0, 0, 0, 0,	"Wooper"},
  {"Maraistre",		95, 85, 85, 65, 65, 35,		Eau, Sol,		14, 750,	90, 4,	EggGroup_Water1 | EggGroup_Field, 21, 70,		137, MediumFast,	2, 0, 0, 0, 0, 0,	"Quagsire"},
  {"Mentali",		65, 65, 60, 130, 95, 110,	Psy, None,		9, 265,		45, 7,	EggGroup_Field, 36, 70,		197, MediumFast,	0, 0, 0, 2, 0, 0,	"Espeon"},
  {"Noctali",		95, 65, 110, 60, 130, 65,	Tenebres, None,		10, 270,	45, 7,	EggGroup_Field, 36, 70,		197, MediumFast,	0, 0, 0, 0, 2, 0,	"Umbreon"},
  {"Cornebre",		60, 85, 42, 85, 42, 91,		Tenebres, Vol,		5, 21,		30, 4,	EggGroup_Flying, 21, 35,		107, MediumSlow,	0, 0, 0, 0, 0, 1,	"Murkrow"},
  {"Roigada",		95, 75, 80, 100, 110, 30,	Eau, Psy,		20, 795,	70, 4,	EggGroup_Monster | EggGroup_Water1, 21, 70,		164, MediumFast,	0, 0, 0, 0, 3, 0,	"Slowking"},
  {"Feuforeve",		60, 60, 60, 85, 85, 85,		Spectre, None,		7, 10,		45, 4,	EggGroup_Amorphous, 26, 35,		147, Fast,		0, 0, 0, 0, 1, 0,	"Misdreavus"},
  {"Zarbi",		48, 72, 48, 72, 48, 48,		Psy, None,		5, 50,		225, 9,	EggGroup_Undiscovered, 41, 70,		61, MediumFast,		0, 1, 0, 1, 0, 0,	"Unown"},
  {"Qulbutoke",		190, 33, 58, 33, 58, 33,	Psy, None,		13, 285,	45, 4,	EggGroup_Amorphous, 21, 70,		177, MediumFast,	2, 0, 0, 0, 0, 0,	"Wobbuffet"},
  {"Girafarig",		70, 80, 65, 90, 65, 85,		Normal, Psy,		15, 415,	60, 4,	EggGroup_Field, 21, 70,		149, MediumFast,	0, 0, 0, 2, 0, 0,	"Girafarig"},
  {"Pomdepik",		50, 65, 90, 35, 35, 15,		Insecte, None,		6, 72,		190, 4,	EggGroup_Bug, 21, 70,		60, MediumFast,		0, 0, 1, 0, 0, 0,	"Pineco"},
  {"Foretress",		75, 90, 140, 60, 60, 40,	Insecte, Acier,		12, 1258,	75, 4,	EggGroup_Bug, 21, 70,		118, MediumFast,	0, 0, 2, 0, 0, 0,	"Forretress"},
  {"Insolourdo",	100, 70, 70, 65, 65, 45,	Normal, None,		15, 140,	190, 4,	EggGroup_Field, 21, 70,		75, MediumFast,		1, 0, 0, 0, 0, 0,	"Dunsparce"},
  {"Scorplane",		65, 75, 105, 35, 65, 85,	Sol, Vol,		11, 248,	60, 4,	EggGroup_Bug, 21, 70,		106, MediumSlow,	0, 0, 1, 0, 0, 0,	"Gligar"},
  {"Steelix",		75, 85, 200, 55, 65, 30,	Acier, Sol,		92, 4000,	25, 4,	EggGroup_Mineral, 26, 70,		196, MediumFast,	0, 0, 2, 0, 0, 0,	"Steelix"},
  {"Snubbull",		60, 80, 50, 40, 40, 30,		Normal, None,		6, 78,		190, 2,	EggGroup_Fairy, 21, 70,		63, Fast,		0, 1, 0, 0, 0, 0,	"Snubbull"},
  {"Granbull",		90, 120, 75, 60, 60, 45,	Normal, None,		14, 487,	75, 2,	EggGroup_Fairy, 21, 70,		178, Fast,		0, 2, 0, 0, 0, 0,	"Granbull"},
  {"Qwilfish",		65, 95, 75, 55, 55, 85,		Eau, Poison,		5, 39,		45, 4,	EggGroup_Water2, 21, 70,		100, MediumFast,	0, 1, 0, 0, 0, 0,	"Qwilfish"},
  {"Cizayox",		70, 130, 100, 55, 80, 65,	Insecte, Acier,		18, 1180,	25, 4,	EggGroup_Bug, 26, 70,		200, MediumFast,	0, 2, 0, 0, 0, 0,	"Scizor"},
  {"Caratroc",		20, 10, 230, 10, 230, 5,	Insecte, Roche,		6, 205,		190, 4,	EggGroup_Bug, 21, 70,		80, MediumSlow,		0, 0, 1, 0, 0, 0,	"Shuckle"},
  {"Scarhino",		80, 125, 75, 40, 95, 85,	Insecte, Combat,	15, 540,	45, 4,	EggGroup_Bug, 26, 70,		200, Slow,		0, 2, 0, 0, 0, 0,	"Heracross"},
  {"Farfuret",		55, 95, 55, 35, 75, 115,	Tenebres, Glace,	9, 280,		60, 4,	EggGroup_Field, 21, 35,		132, MediumSlow,	0, 0, 0, 0, 0, 1,	"Sneasel"},
  {"Teddiursa",		60, 80, 50, 50, 50, 40,		Normal, None,		6, 88,		120, 4,	EggGroup_Field, 21, 70,		124, MediumFast,	0, 1, 0, 0, 0, 0,	"Teddiursa"},
  {"Ursaring",		90, 130, 75, 75, 75, 55,	Normal, None,		18, 1258,	60, 4,	EggGroup_Field, 21, 70,		189, MediumFast,	0, 2, 0, 0, 0, 0,	"Ursaring"},
  {"Limagma",		40, 40, 40, 70, 40, 20,		Feu, None,		7, 350,		190, 4,	EggGroup_Amorphous, 21, 70,		78, MediumFast,		0, 0, 0, 1, 0, 0,	"Slugma"},
  {"Volcaropod",	50, 50, 120, 80, 80, 30,	Feu, Roche,		8, 550,		75, 4,	EggGroup_Amorphous, 21, 70,		154, MediumFast,	0, 0, 2, 0, 0, 0,	"Magcargo"},
  {"Marcacrin",		50, 50, 40, 30, 30, 50,		Glace, Sol,		4, 65,		225, 4,	EggGroup_Field, 21, 70,		78, Slow,		0, 1, 0, 0, 0, 0,	"Swinub"},
  {"Cochignon",		100, 100, 80, 60, 60, 50,	Glace, Sol,		11, 558,	75, 4,	EggGroup_Field, 21, 70,		160, Slow,		1, 1, 0, 0, 0, 0,	"Piloswine"},
  {"Corayon",		55, 55, 85, 65, 85, 35,		Eau, Roche,		6, 50,		60, 2,	EggGroup_Water1 | EggGroup_Water3, 21, 70,		113, Fast,		0, 0, 1, 0, 1, 0,	"Corsola"},
  {"Remoraid",		35, 65, 35, 65, 35, 65,		Eau, None,		6, 120,		190, 4,	EggGroup_Water1 | EggGroup_Water2, 21, 70,		78, MediumFast,		0, 0, 0, 1, 0, 0,	"Remoraid"},
  {"Octillery",		75, 105, 75, 105, 75, 45,	Eau, None,		9, 285,		75, 4,	EggGroup_Water1 | EggGroup_Water2, 21, 70,		164, MediumFast,	0, 1, 0, 1, 0, 0,	"Octillery"},
  {"Cadoizo",		45, 55, 45, 65, 45, 75,		Glace, Vol,		9, 160,		45, 4,	EggGroup_Water1 | EggGroup_Field, 21, 70,		183, Fast,		0, 0, 0, 0, 0, 1,	"Delibird"},
  {"Demanta",		65, 40, 70, 80, 140, 70,	Eau, Vol,		21, 2200,	25, 4,	EggGroup_Water1, 26, 70,		168, Slow,		0, 0, 0, 0, 2, 0,	"Mantine"},
  {"Airmure",		65, 80, 140, 40, 70, 70,	Acier, Vol,		17, 505,	25, 4,	EggGroup_Flying, 26, 70,		168, Slow,		0, 0, 2, 0, 0, 0,	"Skarmory"},
  {"Malosse",		45, 60, 30, 80, 50, 65,		Tenebres, Feu,		6, 108,		120, 4,	EggGroup_Field, 26, 35,		114, Slow,		0, 0, 0, 1, 0, 0,	"Houndour"},
  {"Demolosse",		75, 90, 50, 110, 80, 95,	Tenebres, Feu,		14, 350,	45, 4,	EggGroup_Field, 26, 35,		204, Slow,		0, 0, 0, 2, 0, 0,	"Houndoom"},
  {"Hyporoi",		75, 95, 95, 95, 95, 85,		Eau, Dragon,		18, 1520,	45, 4,	EggGroup_Water1 | EggGroup_Dragon, 21, 70,		207, MediumFast,	0, 1, 0, 1, 1, 0,	"Kingdra"},
  {"Phampy",		90, 60, 60, 40, 40, 40,		Sol, None,		5, 335,		120, 4,	EggGroup_Field, 21, 70,		124, MediumFast,	1, 0, 0, 0, 0, 0,	"Phanpy"},
  {"Donphan",		90, 120, 120, 60, 60, 50,	Sol, None,		11, 1200,	60, 4,	EggGroup_Field, 21, 70,		189, MediumFast,	0, 1, 1, 0, 0, 0,	"Donphan"},
  {"Porygon2",		85, 80, 90, 105, 95, 60,	Normal, None,		6, 325,		45, 9,	EggGroup_Mineral, 21, 70,		180, MediumFast,	0, 0, 0, 2, 0, 0,	"Porygon2"},
  {"Cerfrousse",	73, 95, 62, 85, 65, 85,		Normal, None,		14, 712,	45, 4,	EggGroup_Field, 21, 70,		165, Slow,		0, 1, 0, 0, 0, 0,	"Stantler"},
  {"Quelorior",		55, 20, 35, 20, 45, 75,		Normal, None,		12, 580,	45, 4,	EggGroup_Field, 21, 70,		106, Fast,		0, 0, 0, 0, 0, 1,	"Smeargle"},
  {"Debugant",		35, 35, 35, 35, 35, 35,		Combat, None,		7, 210,		75, 8,	EggGroup_Undiscovered, 26, 70,		91, MediumFast,		0, 1, 0, 0, 0, 0,	"Tyrogue"},
  {"Kapoera",		50, 95, 95, 35, 110, 70,	Combat, None,		14, 480,	45 ,8,	EggGroup_Human_Like, 26, 70,		136, MediumFast,	0, 0, 0, 0, 2, 0,	"Hitmontop"},
  {"Lippouti",		45, 30, 15, 85, 65, 65,		Glace, Psy,		4, 60,		45, 0,	EggGroup_Undiscovered, 26, 70,		85, MediumFast,		0, 0, 0, 1, 0, 0,	"Smoochum"},
  {"Elekid",		45, 63, 37, 65, 55, 95,		Electric, None,		6, 235,		45, 6,	EggGroup_Undiscovered, 26, 70,		106, MediumFast,	0, 0, 0, 0, 0, 1,	"Elekid"},
  {"Magby",		45, 75, 37, 70, 55, 83,		Feu, None,		7, 214,		45, 6,	EggGroup_Undiscovered, 26, 70,		117, MediumFast,	0, 0, 0, 0, 0, 1,	"Magby"},
  {"Ecremeuh",		95, 80, 105, 40, 70, 100,	Normal, None,		12, 755,	45, 0,	EggGroup_Field, 21, 70,		200, Slow,		0, 0, 2, 0, 0, 0,	"Miltank"},
  {"Leuphorie",		255, 10, 10, 75, 135, 55,	Normal, None,		15, 468,	30, 0,	EggGroup_Fairy, 41, 140,	255, Fast,		3, 0, 0, 0, 0, 0,	"Blissey"},
  {"Raikou",		90, 85, 75, 115, 100, 115,	Electric, None,		19, 1780,	3, 9,	EggGroup_Undiscovered, 81, 35,		216, Slow,		0, 0, 0, 1, 0, 2,	"Raikou"},
  {"Entei",		115, 115, 85, 90, 75, 100,	Feu, None,		21, 1980,	3, 9,	EggGroup_Undiscovered, 81, 35,		217, Slow,		1, 2, 0, 0, 0, 0,	"Entei"},
  {"Suicune",		100, 75, 115, 90, 115, 85,	Eau, None,		20, 1870,	3, 9,	EggGroup_Undiscovered, 81, 35,		215, Slow,		0, 0, 1, 0, 2, 0,	"Suicune"},
  {"Embrylex",		50, 64, 50, 45, 50, 41,		Roche, Sol,		6, 720,		45, 4,	EggGroup_Monster, 41, 35,		67, Slow,		0, 1, 0, 0, 0, 0,	"Larvitar"},
  {"Ymphect",		70, 84, 70, 65, 70, 51,		Roche, Sol,		12, 1520,	45, 4,	EggGroup_Monster, 41, 35,		144, Slow,		0, 2, 0, 0, 0, 0,	"Pupitar"},
  {"Tyranocif",		100, 134, 110, 95, 100, 61,	Roche, Tenebres,	20, 2020,	45, 4,	EggGroup_Monster, 41, 35,		218, Slow,		0, 3, 0, 0, 0, 0,	"Tyranitar"},
  {"Lugia",		106, 90, 130, 90, 154, 110,	Psy, Vol,		52, 2160,	3, 9,	EggGroup_Undiscovered, 121, 0,		220, Slow,		0, 0, 0, 0, 3, 0,	"Lugia"},
  {"Ho-Oh",		106, 130, 90, 110, 154, 90,	Feu, Vol,		38, 1990,	3, 9,	EggGroup_Undiscovered, 121, 0,		220, Slow,		0, 0, 0, 0, 3, 0,	"Ho-Oh"},
  {"Celebi",		100, 100, 100, 100, 100, 100,	Psy, Plante,		6, 50,		45, 9,	EggGroup_Undiscovered, 121, 100,	64, MediumSlow,		3, 0, 0, 0, 0, 0,	"Celebi"},
  {NULL, 0, 0, 0, 0, 0, 0, None, None, 0, 0, 0, 0, None, 0, 0, 0, Undefined,	0, 0, 0, 0, 0, 0, NULL}
};

const t_ability		abilities_db[] =
{
  // Class Name			Type              Category              PP/Pow/Acc/Crit/turn/OHKO
  {	"Unused",		None,		Ability_None,		0, 0, 0, 0, 0, false,		0,None,		"Unused"	},	// Unused
  {	"Ecras'Face",		Normal,		Ability_Physical,	35, 40, 100, 0, 1, false,	0,None,		"Pound"	},	// Pound
  {	"Poing Karate",		Combat,		Ability_Physical,	25, 50, 100, 2, 1, false,	0,None,		"Karate Chop"	},	// Karate Chop
  {	"Torgnoles",		Normal,		Ability_Physical,	10, 15, 85, 0, 1, false,	0,None,		"Double Slap"	},	// Double Slap
  {	"Poing Comete",		Normal,		Ability_Physical,	15, 18, 85, 0, 1, false,	0,None,		"Comet Punch"	},	// Comet Punch
  {	"Ultimapoing",		Normal,		Ability_Physical,	20, 80, 85, 0, 1, false,	0,None,		"Mega Punch"	},	// Mega Punch
  {	"Jackpot",		Normal,		Ability_Physical,	20, 40, 100, 0, 1, false,	0,None,		"Pay day"	},	// Pay day
  {	"Poing de feu",		Feu,		Ability_Physical,	15, 75, 100, 0, 1, false,	10, Status_BRN,	"Fire Punch"	},	// Fire Punch
  {	"Poinglace",		Glace,		Ability_Physical,	15, 75, 100, 0, 1, false,	10, Status_FRZ,	"Ice Punch"	},	// Ice Punch
  {	"Poing Eclair",		Electric,	Ability_Physical,	15, 75, 100, 0, 1, false,	10, Status_PAR,	"Thunder Punch"	},	// Thunder Punch
  {	"Griffe",		Normal,		Ability_Physical,	35, 40, 100, 0, 1, false,	0,None,		"Scrach"	},	// Scrach
  {	"Force Poigne",		Normal,		Ability_Physical,	30, 55, 100, 0, 1, false,	0,None,		"Vice Grip"	},	// Vice Grip
  {	"Guillotine",		Normal,		Ability_Physical,	5, 0, 0, 0, 1, true,		0,None,		"Guillotine"	},	// Guillotine
  {	"Coupe-Vent",		Normal,		Ability_Special,	10, 80, 100, 2, 2, false,	0,None,		"Razor Wind"	},	// Razor Wind
  {	"Danse-Lames",		Normal,		Ability_Status,		0, 2, 0, 0, 1, false,		0,None,		"Swords Dance"	},	// Swords Dance
  {	"Coupe",		Normal,		Ability_Physical,	30, 50, 95, 0, 1, false,	0,None,		"Cut"	},	// Cut
  {	"Tornade",		Vol,		Ability_Special,	35, 40, 100, 0, 1, false,	0,None,		"Gust"	},	// Gust
  {	"Cru-Aile",		Vol,		Ability_Physical,	35, 60, 100, 0, 1, false,	0,None,		"Wing Attack"	},	// Wing Attack
  {	"Cyclone",		Vol,		Ability_Status,		0, 0, 100, 0, 1, false,		0,None,		"Whirlwind"	},	// Whirlwind
  {	"Vol",			Vol,		Ability_Physical,	15, 70, 95, 0, 2, false,	0,None,		"Fly"	},	// Fly
  {	"Etreinte",		Normal,		Ability_Physical,	10, 15, 70, 0, 1, false,	0,None,		"Bind"	},	// Bind
  {	"Souplesse",		Normal,		Ability_Physical,	20, 80, 75, 0, 1, false,	0,None,		"Slam"	},	// Slam
  {	"Fouet Lianes",		Plante,		Ability_Physical,	10, 35, 100, 0, 1, false,	0,None,		"Vine Whip"	},	// Vine Whip
  {	"Ecrasement",		Normal,		Ability_Physical,	20, 65, 100, 0, 1, false,	0,None,		"Stomp"	},	// Stomp
  {	"Double Pied",		Combat,		Ability_Physical,	30, 30, 100, 0, 1, false,	0,None,		"Double Kick"	},	// Double Kick
  {	"Ultimawashi",		Normal,		Ability_Physical,	5, 120, 75, 0, 1, false,	0,None,		"Mega Kick"	},	// Mega Kick
  {	"Pied Saute",		Combat,		Ability_Physical,	25, 70, 95, 0, 1, false,	0,None,		"Jump Kick"	},	// Jump Kick
  {	"Mawashi Geri",		Combat,		Ability_Physical,	15, 60, 85, 0, 1, false,	0,None,		"Rolling Kick"	},	// Rolling Kick
  {	"Jet de sable",		Sol,		Ability_Status,		5, 1, 100, 0, 1, false,		0,None,		"Sand Attack"	},	// Sand Attack
  {	"Coup d'Boule",		Normal,		Ability_Physical,	15, 70, 100, 0, 1, false,	0,None,		"Headbutt"	},	// Headbutt
  {	"Koud'Korne",		Normal,		Ability_Physical,	25, 65, 100, 0, 1, false,	0,None,		"Horn Attack"	},	// Horn Attack
  {	"Furie",		Normal,		Ability_Physical,	20, 15, 85, 0, 1, false,	0,None,		"Fury Attack"	},	// Fury Attack
  {	"Empal'Korne",		Normal,		Ability_Physical,	5, 0, 0, 0, 1, true,		0,None,		"Horn Drill"	},	// Horn Drill
  {	"Charge",		Normal,		Ability_Physical,	35, 35, 95, 0, 1, false,	0,None,		"Tackle"	},	// Tackle
  {	"Plaquage",		Normal,		Ability_Physical,	15, 85, 100, 0, 1, false,	30, Status_PAR,	"Body Slam"	},	// Body Slam
  {	"Ligotage",		Normal,		Ability_Physical,	20, 15, 85, 0, 1, false,	0,None,		"Wrap"	},	// Wrap
  {	"Belier",		Normal,		Ability_Physical,	20, 90, 85, 0, 1, false,	0,None,		"Take Down"	},	// Take Down
  {	"Mania",		Normal,		Ability_Physical,	20, 90, 100, 0, 2, false,	0,None,		"Thrash"	},	// Thrash
  {	"Damocles",		Normal,		Ability_Physical,	15, 120, 100, 0, 1, false,	0,None,		"Double-Edge"	},	// Double-Edge
  {	"Mimi-Queue",		Normal,		Ability_Status,		0, 1, 100, 0, 1, false,		0,None,		"Tail Whip"	},	// Tail Whip
  {	"Dard-Venin",		Poison,		Ability_Physical,	35, 15, 100, 0, 1, false,	30, Status_PSN,	"Poison Sting"	},	// Poison Sting
  {	"Double-Dard",		Insecte,	Ability_Physical,	20, 25, 100, 0, 1, false,	20, Status_PSN,	"Twineedle"	},	// Twineedle
  {	"Dard-Nuee",		Insecte,	Ability_Physical,	20, 14, 85, 0, 1, false,	0,None,		"Pin Missile"	},	// Pin Missile
  {	"Groz'Yeux",		Normal,		Ability_Status,		0, 1, 100, 0, 1, false,		0,None,		"Leer"	},	// Leer
  {	"Morsure",		Tenebres,	Ability_Special,	25, 60, 100, 0, 1, false,	0,None,		"Bite"	},	// Bite
  {	"Rugissement",		Normal,		Ability_Status,		0, 1, 100, 0, 1, false,		0,None,		"Growl"	},	// Growl
  {	"Hurlement",		Normal,		Ability_Status,		0, 0, 100, 0, 1, false,		0,None,		"Roar"	},	// Roar
  {	"Berceuse",		Normal,		Ability_Status,		5, 0, 55, 0, 1, false,		0,None,		"Sing"	},	// Sing
  {	"Ultrason",		Normal,		Ability_Status,		0, 0, 55, 0, 1, false,		0,None,		"Supersonic"	},	// Supersonic
  {	"Sonicboom",		Normal,		Ability_Special,	20, 20, 90, 0, 1, false,	0,None,		"Sonic Boom"	},	// Sonic Boom
  {	"Entrave",		Normal,		Ability_Status,		0, 0, 55, 0, 1, false,		0,None,		"Disable"	},	// Disable
  {	"Acide",		Poison,		Ability_Special,	30, 40, 100, 0, 1, false,	0,None,		"Acid"	},	// Acid
  {	"Flammeche",		Feu,		Ability_Special,	25, 40, 100, 0, 1, false,	10, Status_BRN,	"Ember"	},	// Ember
  {	"Lance-Flamme",		Feu,		Ability_Special,	15, 90, 100, 0, 1, false,	10, Status_BRN,	"Flamethrower"	},	// Flamethrower
  {	"Brume",		Glace,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Mist"	},	// Mist
  {	"Pistolet A O",		Eau,		Ability_Special,	25, 40, 100, 0, 1, false,	0,None,		"Water Gun"	},	// Water Gun
  {	"Hydrocanon",		Eau,		Ability_Special,	5, 110, 80, 0, 1, false,	0,None,		"Hydro Pump"	},	// Hydro Pump
  {	"Surf",			Eau,		Ability_Special,	15, 90, 100, 0, 1, false,	0,None,		"Surf"	},	// Surf
  {	"Laser Glace",		Glace,		Ability_Special,	10, 90, 100, 0, 1, false,	10, Status_FRZ,	"Ice Beam"	},	// Ice Beam
  {	"Blizzard",		Glace,		Ability_Special,	5, 120, 90, 0, 1, false,	10, Status_FRZ,	"Blizzard"	},	// Blizzard
  {	"Rafale Psy",		Psy,		Ability_Special,	20, 65, 100, 0, 1, false,	0,None,		"Psybeam"	},	// Psybeam
  {	"Bulles d'O",		Eau,		Ability_Special,	20, 65, 100, 0, 1, false,	0,None,		"Bubble beam"	},	// Bubble beam
  {	"Onde Boreale",		Glace,		Ability_Special,	20, 65, 100, 0, 1, false,	0,None,		"Aurora Beam"	},	// Aurora Beam
  {	"Ultralaser",		Normal,		Ability_Special,	5, 150, 90, 0, 2, false,	0,None,		"Hyper Beam"	},	// Hyper Beam
  {	"Picpic",		Vol,		Ability_Physical,	35, 35, 100, 0, 1, false,	0,None,		"Peck"	},	// Peck
  {	"Bec Vrille",		Vol,		Ability_Physical,	20, 80, 100, 0, 1, false,	0,None,		"Drill Peck"	},	// Drill Peck
  {	"Sacrifice",		Combat,		Ability_Physical,	25, 80, 80, 0, 1, false,	0,None,		"Submission"	},	// Submission
  {	"Balayage",		Combat,		Ability_Physical,	20, 50, 100, 0, 1, false,	0,None,		"Low Kick"	},	// Low Kick
  {	"Riposte",		Combat,		Ability_Physical,	20, 0, 100, 0, 1, false,	0,None,		"Counter"	},	// Counter
  {	"Frappe Atlas",		Combat,		Ability_Physical,	20, 0, 100, 0, 1, false,	0,None,		"Seismic Toss"	},	// Seismic Toss
  {	"Force",		Normal,		Ability_Physical,	15, 80, 100, 0, 1, false,	0,None,		"Strength"	},	// Strength
  {	"Vol-Vie",		Plante,		Ability_Special,	20, 20, 100, 0, 1, false,	0,None,		"Absorb"	},	// Absorb
  {	"Mega-Sangsue",		Plante,		Ability_Special,	10, 40, 100, 0, 1, false,	0,None,		"Mega Drain"	},	// Mega Drain
  {	"Vampigraine",		Plante,		Ability_Status,		0, 0, 90, 0, 1, false,		0,None,		"Leech Seed"	},	// Leech Seed
  {	"Croissance",		Normal,		Ability_Status,		0, 1, 0, 0, 1, false,		0,None,		"Growth"	},	// Growth
  {	"Tranch'herbe",		Plante,		Ability_Physical,	25, 55, 95, 2, 1, false,	0,None,		"Razor Leaf"	},	// Razor Leaf
  {	"Lance-Soleil",		Plante,		Ability_Special,	10, 120, 100, 0, 2, false,	0,None,		"Solar Beam"	},	// Solar Beam
  {	"Poudre Toxik",		Poison,		Ability_Status,		5, 0, 75, 0, 1, false,		100, Status_PSN,	"Poison Powder"	},	// Poison Powder
  {	"Para Spore",		Plante,		Ability_Status,		0, 0, 75, 0, 1, false,		100, Status_PAR,	"Stun Spore"	},	// Stun Spore
  {	"Poudre Dodo",		Plante,		Ability_Status,		5, 0, 75, 0, 1, false,		100, Status_SLP,	"Sleep Powder"	},	// Sleep Powder
  {	"Danse-Fleur",		Plante,		Ability_Special,	20, 70, 100, 0, 2, false,	0,None,		"Petal Dance"	},	// Petal Dance
  {	"Secretion",		Insecte,	Ability_Status,		0, 1, 95, 0, 1, false,		0,None,		"String Shot"	},	// String Shot
  {	"Draco-Rage",		Dragon,		Ability_Special,	10, 40, 100, 0, 1, false,	0,None,		"Dragon Rage"	},	// Dragon Rage
  {	"Danseflamme",		Feu,		Ability_Special,	15, 15, 70, 0, 1, false,	0,None,		"Fire Spin"	},	// Fire Spin
  {	"Eclair",		Electric,	Ability_Special,	30, 40, 100, 0, 1, false,	10, Status_PAR,	"Thunder Shock"	},	// Thunder Shock
  {	"Tonnerre",		Electric,	Ability_Special,	15, 95, 100, 0, 1, false,	10, Status_PAR,	"Thunderbolt"	},	// Thunderbolt
  {	"Cage-Eclair",		Electric,	Ability_Status,		0, 0, 100, 0, 1, false,		100, Status_PAR,	"Thunder Wave"	},	// Thunder Wave
  {	"Fatal-Foudre",		Electric,	Ability_Status,		0, 120, 70, 0, 1, false,	30, Status_PAR,	"Thunder"	},	// Thunder
  {	"Jet-Pierres",		Roche,		Ability_Physical,	15, 50, 90, 0, 1, false,	0,None,		"Rock Throw"	},	// Rock Throw
  {	"Seisme",		Sol,		Ability_Physical,	10, 100, 100, 0, 1, false,	0,None,		"Earthquake"	},	// Earthquake
  {	"Abime",		Sol,		Ability_Physical,	5, 0, 0, 0, 1, true,		0,None,		"Fissure"	},	// Fissure
  {	"Tunnel",		Sol,		Ability_Physical,	10, 60, 100, 0, 2, false,	0,None,		"Dig"	},	// Dig
  {	"Toxik",		Poison,		Ability_Status,		0, 0, 85, 0, 1, false,		100, Status_BPSN,"Toxic"},	// Toxic
  {	"Choc Mental",		Psy,		Ability_Special,	25, 50, 100, 1, 1, false,	0,None,		"Confusion"	},	// Confusion
  {	"Psyko",		Psy,		Ability_Special,	10, 90, 100, 0, 1, false,	0,None,		"Psychic"	},	// Psychic
  {	"Hypnose",		Psy,		Ability_Status,		0, 0, 60, 0, 1, false,		100, Status_SLP,	"Hypnosis"	},	// Hypnosis
  {	"Meditation",		Psy,		Ability_Status,		0, 1, 0, 0, 1, false,		0,None,		"Meditate"	},	// Meditate
  {	"Hate",			Psy,		Ability_Status,		0, 2, 0, 0, 1, false,		0,None,		"Agility"	},	// Agility
  {	"Vive-Attaque",		Normal,		Ability_Physical,	30, 40, 100, 0, 1, false,	0,None,		"Quick Attack"	},	// Quick Attack
  {	"Frenesie",		Normal,		Ability_Physical,	20, 20, 100, 0, 1, false,	0,None,		"Rage"	},	// Rage
  {	"Teleport",		Psy,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Teleport"	},	// Teleport
  {	"Tenebres",		Spectre,	Ability_Special,	20, 0, 100, 0, 1, false,	0,None,		"Night Shade"	},	// Night Shade
  {	"Copie",		Normal,		Ability_Status,		10, 0, 0, 0, 1, false,		0,None,		"Mimic"	},	// Mimic
  {	"Grincement",		Normal,		Ability_Status,		0, 2, 85, 0, 1, false,		0,None,		"Screech"	},	// Screech
  {	"Esquive",		Normal,		Ability_Status,		5, 1, 0, 0, 1, false,		0,None,		"Double Team"	},	// Double Team
  {	"Soin",			Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Recover"	},	// Recover
  {	"Armure",		Normal,		Ability_Status,		0, 1, 0, 0, 1, false,		0,None,		"Harden"	},	// Harden
  {	"Lilliput",		Normal,		Ability_Status,		0, 1, 0, 0, 1, false,		0,None,		"Minimize"	},	// Minimize
  {	"Brouillard",		Normal,		Ability_Status,		0, 1, 100, 0, 1, false,		0,None,		"Smokescreen"	},	// Smokescreen
  {	"Onde Folie",		Spectre,	Ability_Status,		0, 0, 100, 0, 1, false,		0,None,		"Confuse ray"	},	// Confuse ray
  {	"Replis",		Eau,		Ability_Status,		0, 1, 0, 0, 1, false,		0,None,		"Withdraw"	},	// Withdraw
  {	"Boul'Armure",		Normal,		Ability_Status,		0, 1, 0, 0, 1, false,		0,None,		"Defense Curl"	},	// Defense Curl
  {	"Bouclier",		Psy,		Ability_Status,		0, 2, 0, 0, 1, false,		0,None,		"Barrier"	},	// Barrier
  {	"Mur Lumiere",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Light Screen"	},	// Light Screen
  {	"Buee Noire",		Glace,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Haze"	},	// Haze
  {	"Protection",		Psy,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Reflect"	},	// Reflect
  {	"Puissance",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Focus Energy"	},	// Focus Energy
  {	"Patience",		Normal,		Ability_Physical,	10, 0, 0, 0, 1, false,		0,None,		"Bide"	},	// Bide
  {	"Metronome",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Metroneme"	},	// Metroneme
  {	"Mimique",		Vol,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Mirror Move"	},	// Mirror Move
  {	"Destruction",		Normal,		Ability_Physical,	5, 200, 100, 0, 1, false,	0,None,		"Self-Destruct"	},	// Self-Destruct
  {	"Bomb'oeuf",		Normal,		Ability_Physical,	10, 100, 75, 0, 1, false,	0,None,		"Egg Bomb"	},	// Egg Bomb
  {	"Lechouille",		Spectre,	Ability_Physical,	30, 30, 100, 0, 1, false,	30, Status_PAR,	"Lick"	},	// Lick
  {	"Puredpois",		Poison,		Ability_Special,	20, 20, 70, 0, 1, false,	40, Status_PSN,	"Smog"	},	// Smog
  {	"Detritus",		Poison,		Ability_Special,	20, 65, 100, 0, 1, false,	30, Status_PAR,	"Sludge"	},	// Sludge
  {	"Massd'os",		Sol,		Ability_Physical,	20, 65, 85, 0, 1, false,	0,None,		"Bone Club"	},	// Bone Club
  {	"Deflagration",		Feu,		Ability_Special,	5, 120, 85, 0, 1, false,	10, Status_BRN,	"Fire Blast"	},	// Fire Blast
  {	"Cascade",		Eau,		Ability_Special,	15, 80, 100, 0, 1, false,	0,None,		"Water Fall"	},	// Water Fall
  {	"Claquoir",		Eau,		Ability_Physical,	10, 35, 85, 0, 1, false,	0,None,		"Clamp"	},	// Clamp
  {	"Meteore",		Normal,		Ability_Physical,	20, 60, 0, 0, 1, false,		0,None,		"Swift"	},	// Swift
  {	"Coud'Krane",		Normal,		Ability_Physical,	10, 100, 100, 0, 1, false,	0,None,		"Skull Bash"	},	// Skull Bash
  {	"Picanon",		Normal,		Ability_Physical,	15, 20, 100, 0, 1, false,	0,None,		"Spike Canon"	},	// Spike Canon
  {	"Constriction",		Normal,		Ability_Physical,	35, 10, 100, 0, 1, false,	0,None,		"Constrict"	},	// Constrict
  {	"Amnesie",		Psy,		Ability_Status,		0, 2, 0, 0, 1, false,		0,None,		"Amnesia"	},	// Amnesia
  {	"Telekinesie",		Psy,		Ability_Status,		5, 1, 80, 0, 1, false,		0,None,		"Kinesis"	},	// Kinesis
  {	"E-Coque",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"SoftBoiled"	},	// SoftBoiled
  {	"Pied Voltige",		Combat,		Ability_Physical,	20, 85, 90, 0, 1, false,	0,None,		"High Jump Kick"	},	// High Jump Kick
  {	"Intimidation",		Normal,		Ability_Status,		0, 0, 75, 0, 1, false,		100, Status_PAR,	"Glare"	},	// Glare
  {	"Devoreve",		Psy,		Ability_Special,	15, 100, 100, 0, 1, false,	0,None,		"Dream Eater"	},	// Dream Eater
  {	"Gaz toxik",		Poison,		Ability_Status,		0, 0, 55, 0, 1, false,		100, Status_PSN,	"Posion Gas"	},	// Posion Gas
  {	"Pilonnage",		Normal,		Ability_Physical,	20, 15, 85, 0, 1, false,	0,None,		"Barrage"	},	// Barrage
  {	"Vampirisme",		Insecte,	Ability_Physical,	15, 20, 100, 0, 1, false,	0,None,		"Leech Life"	},	// Leech Life
  {	"Grobisous",		Normal,		Ability_Status,		0, 0, 75, 0, 1, false,		100, Status_SLP,	"Lovely Kiss"	},	// Lovely Kiss
  {	"Pique",		Vol,		Ability_Physical,	5, 140, 90, 0, 2, false,	0,None,		"Sky Attack"	},	// Sky Attack
  {	"Morphing",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Transform"	},	// Transform
  {	"Ecume",		Eau,		Ability_Special,	30, 20, 100, 0, 1, false,	0,None,		"Bubble"	},	// Bubble
  {	"Uppercut",		Normal,		Ability_Physical,	10, 70, 100, 0, 1, false,	0,None,		"Dizzy Punch"	},	// Dizzy Punch
  {	"Spore",		Plante,		Ability_Status,		5, 0, 100, 0, 1, false,		100,Status_SLP,	"Spore"	},	// Spore
  {	"Flash",		Normal,		Ability_Status,		0, 0, 70, 0, 1, false,		0,None,		"Flash"	},	// Flash
  {	"Vague Psy",		Psy,		Ability_Special,	15, 0, 80, 0, 1, false,		0,None,		"Psywave"	},	// Psywave
  {	"Trempette",		Normal,		Ability_Status,		0, 0, 100, 0, 1, false,		0,None,		"Splash"	},	// Splash
  {	"Acidarmure",		Poison,		Ability_Status,		0, 2, 0, 0, 1, false,		0,None,		"Acid Armor"	},	// Acid Armor
  {	"Pince-Masse",		Eau,		Ability_Physical,	10, 90, 85, 2, 1, false,	0,None,		"Crabhammer"	},	// Crabhammer
  {	"Explosion",		Normal,		Ability_Physical,	5, 250, 100, 0, 1, false,	0,None,		"Explosion"	},	// Explosion
  {	"Combo-griffe",		Normal,		Ability_Physical,	15, 18, 80, 0, 1, false,	0,None,		"Fury Swipes"	},	// Fury Swipes
  {	"Osmerang",		Sol,		Ability_Physical,	10, 50, 90, 0, 1, false,	0,None,		"Bonemerang"	},	// Bonemerang
  {	"Repos",		Normal,		Ability_Physical,	10, 0, 0, 0, 1, false,		0,None,		"Rest"	},	// Rest
  {	"Eboulement",		Roche,		Ability_Physical,	10, 75, 90, 0, 1, false,	0,None,		"Rock Slide"	},	// Rock Slide
  {	"Croc de mort",		Normal,		Ability_Physical,	15, 80, 90, 0, 1, false,	0,None,		"Hyper Fang"	},	// Hyper Fang
  {	"Armure",		Normal,		Ability_Status,		0, 1, 0, 0, 1, false,		0,None,		"Sharpen"	},	// Sharpen
  {	"Adaptation",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Conversion"	},	// Conversion
  {	"Triplattaque",		Normal,		Ability_Special,	10, 80, 100, 0, 1, false,	20,Status_SLP,	"Tri Attack"	},	// Tri Attack
  {	"Croc Fatal",		Normal,		Ability_Physical,	10, 0, 90, 0, 1, false,		0,None,		"Super Fang"	},	// Super Fang
  {	"Tranche",		Normal,		Ability_Physical,	20, 70, 100, 2, 1, false,	0,None,		"Slash"	},	// Slash
  {	"Clonage",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Substitute"	},	// Substitute
  {	"Lutte",		None,		Ability_Physical,	0, 50, 0, 0, 1, false,		0,None,		"Struggle"	},	// Struggle
  {	"Gribouille",		Normal,		Ability_Status,		1, 0, 0, 0, 1, false,		0,None,		"Sketch"	},	// Sketch
  {	"Triple-Pied",		Combat,		Ability_Physical,	10, 10, 90, 0, 1, false,	0,None,		"Triple Kick"	},	// Triple Kick
  {	"Larcin",		Tenebres,	Ability_Physical,	10, 40, 100, 0, 1, false,	0,None,		"Thief"	},	// Thief
  {	"Toile",		Insecte,	Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Spider Web"	},	// Spider Web
  {	"Lire-Esprit",		Normal,		Ability_Status,		5, 0, 100, 0, 1, false,		0,None,		"Mind Reader"	},	// Mind Reader
  {	"Cauchemar",		Spectre,	Ability_Status,		5, 0, 100, 0, 1, false,		0,None,		"Nightmare"	},	// Nightmare
  {	"Roue de Feu",		Feu,		Ability_Physical,	25, 60, 100, 0, 1, false,	10,Status_BRN,	"Flame Wheel"	},	// Flame Wheel
  {	"Ronflement",		Normal,		Ability_Special,	15, 40, 100, 0, 1, false,	0,None,		"Snore"	},	// Snore
  {	"Malediction",		Spectre,	Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Curse"	},	// Curse
  {	"Fleau",		Normal,		Ability_Physical,	15, 0, 100, 0, 1, false,	0,None,		"Flail"	},	// Flail
  {	"Adaptation2",		Normal,		Ability_Status,		0, 00, 0, 0, 1, false,		0,None,		"Conversion2"	},	// Conversion2
  {	"Aeroblast",		Vol,		Ability_Special,	5, 100, 95, 0, 1, false,	0,None,		"Aeroblast"	},	// Aeroblast
  {	"Spore-Coton",		Plante,		Ability_Status,		0, 2, 85, 0, 1, false,		0,None,		"Cotton Spore"	},	// Cotton Spore
  {	"Contre",		Combat,		Ability_Physical,	15, 0, 100, 0, 1, false,	0,None,		"Reversal"	},	// Reversal
  {	"Depit",		Spectre,	Ability_Status,		0, 0, 100, 0, 1, false,		0,None,		"Splite"	},	// Splite
  {	"Poudreuse",		Glace,		Ability_Special,	25, 40, 100, 0, 1, false,	10,Status_FRZ,	"Powder Snow"	},	// Powder Snow
  {	"Abris",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Protect"	},	// Protect
  {	"Mach Punch",		Combat,		Ability_Physical,	30, 40, 100, 0, 1, false,	0,None,		"Mach Punch"	},	// Mach Punch
  {	"Grimace",		Normal,		Ability_Status,		0, 2, 90, 0, 1, false,		0,None,		"Scary Face"	},	// Scary Face
  {	"Feinte",		Tenebres,	Ability_Physical,	20, 60, 0, 0, 1, false,		0,None,		"Feint Attack"	},	// Feint Attack
  {	"Doux Baiser",		Normal,		Ability_Status,		0, 0, 75, 0, 1, false,		0,None,		"Sweet Kiss"	},	// Sweet Kiss
  {	"Cognobidon",		Normal,		Ability_Status,		0, 13, 0, 0, 1, false,		0,None,		"Belly Drum"	},	// Belly Drum
  {	"Bomb-Beurk",		Poison,		Ability_Special,	10, 90, 100, 0, 1, false,	30,Status_PSN,	"Sludge Bomb"	},	// Sludge Bomb
  {	"Coud'Boue",		Sol,		Ability_Special,	10, 20, 100, 0, 1, false,	0,None,		"Mud-Slap"	},	// Mud-Slap
  {	"Octazooka",		Eau,		Ability_Special,	10, 65, 85, 0, 1, false,	0,None,		"Octazooka"	},	// Octazooka
  {	"Picots",		Sol,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Spikes"	},	// Spikes
  {	"Elecanon",		Electric,	Ability_Special,	5, 100, 100, 0, 1, false,	100,Status_PAR,	"Zap Cannon"	},	// Zap Cannon
  {	"Clairvoyance",		Normal,		Ability_Status,		0, 0, 100, 0, 1, false,		0,None,		"ForeSight"	},	// ForeSight
  {	"Prlvt Destin",		Spectre,	Ability_Status,		5, 0, 0, 0, 1, false,		0,None,		"Destiny Bond"	},	// Destiny Bond
  {	"Requiem",		Normal,		Ability_Status,		5, 0, 0, 0, 1, false,		0,None,		"Perish Song"	},	// Perish Song
  {	"Vent Glace",		Glace,		Ability_Special,	15, 55, 95, 0, 1, false,	0,None,		"Ice Wind"	},	// Ice Wind
  {	"Detection",		Combat,		Ability_Status,		5, 0, 0, 0, 1, false,		0,None,		"Detect"	},	// Detect
  {	"Charge-Os",		Sol,		Ability_Physical,	10, 25, 80, 0, 1, false,	0,None,		"Bone Rush"	},	// Bone Rush
  {	"Verrouillage",		Normal,		Ability_Status,		5, 0, 0, 0, 1, false,		0,None,		"Lock-On"	},	// Lock-On
  {	"Colere",		Dragon,		Ability_Physical,	15, 90, 100, 0, 2, false,	0,None,		"Outrage"	},	// Outrage
  {	"Tempetesable",		Roche,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Sandstorm"	},	// Sandstorm
  {	"Giga-Sangsue",		Plante,		Ability_Special,	5, 60, 100, 0, 1, false,	0,None,		"Giga Drain"	},	// Giga Drain
  {	"Tenacite",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Endure"	},	// Endure
  {	"Charme",		Normal,		Ability_Status,		0, 2, 100, 0, 1, false,		0,None,		"Charm"	},	// Charm
  {	"Roulade",		Roche,		Ability_Physical,	20, 30, 90, 0, 5, false,	0,None,		"Rollout"	},	// Rollout
  {	"Faux-Chage",		Normal,		Ability_Physical,	40, 40, 100, 0, 1, false,	0,None,		"False Swipe"	},	// False Swipe
  {	"Vantardise",		Normal,		Ability_Status,		5, 2, 90, 0, 1, false,		0,None,		"Swagger"	},	// Swagger
  {	"Lait a Boire",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Milk Drink"	},	// Milk Drink
  {	"Etincelle",		Electric,	Ability_Physical,	20, 65, 100, 0, 1, false,	30,Status_PAR,	"Spark"	},	// Spark
  {	"Taillade",		Insecte,	Ability_Physical,	20, 10, 95, 0, 1, false,	0,None,		"Fury Cutter"	},	// Fury Cutter
  {	"Aile d'Acier",		Acier,		Ability_Physical,	25, 70, 90, 0, 1, false,	0,None,		"Steel Wing"	},	// Steel Wing
  {	"Regard Noir",		Normal,		Ability_Status,		5, 0, 0, 0, 1, false,		0,None,		"Mean Look"	},	// Mean Look
  {	"Attraction",		Normal,		Ability_Status,		5, 0, 100, 0, 1, false,		0,None,		"Attract"	},	// Attract
  {	"Blabla Dodo",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Sleep Talk"	},	// Sleep Talk
  {	"Glas de Soin",		Normal,		Ability_Status,		5, 0, 100, 0, 1, false,		0,None,		"Heal Bell"	},	// Heal Bell
  {	"Retour",		Normal,		Ability_Physical,	20, 0, 100, 0, 1, false,	0,None,		"Return"	},	// Return
  {	"Cadeau",		Normal,		Ability_Physical,	15, 0, 100, 0, 1, false,	0,None,		"Present"	},	// Present
  {	"Frustation",		Normal,		Ability_Physical,	20, 0, 100, 0, 1, false,	0,None,		"Frustration"	},	// Frustration
  {	"Rune Protect",		Normal,		Ability_Status,		5, 0, 0, 0, 1, false,		0,None,		"Safeguard"	},	// Safeguard
  {	"Balance",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Pain Split"	},	// Pain Split
  {	"Feu Sacre",		Feu,		Ability_Special,	5, 100, 95, 0, 1, false,	0,None,		"Sacred Fire"	},	// Sacred Fire
  {	"Magnitude",		Sol,		Ability_Physical,	30, 0, 100, 0, 1, false,	0,None,		"Magnitude"	},	// Magnitude
  {	"Dynamopoing",		Combat,		Ability_Physical,	5, 100, 50, 0, 1, false,	0,None,		"Dynamic Punch"	},	// Dynamic Punch
  {	"Megacorne",		Insecte,	Ability_Physical,	10, 120, 85, 0, 1, false,	0,None,		"Megahorn"	},	// Megahorn
  {	"Dracosouffle",		Dragon,		Ability_Special,	20, 60, 100, 0, 1, false,	30,Status_PAR,	"Dragon Breath"	},	// Dragon Breath
  {	"Relais",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Baton Pass"	},	// Baton Pass
  {	"Encore",		Normal,		Ability_Status,		5, 0, 100, 0, 1, false,		0,None,		"Encore"	},	// Encore
  {	"Poursuite",		Tenebres,	Ability_Physical,	20, 40, 100, 0, 1, false,	0,None,		"Pursuit"	},	// Pursuit
  {	"Tour Rapide",		Eau,		Ability_Physical,	40, 20, 100, 0, 1, false,	0,None,		"Rapid Spin"	},	// Rapid Spin
  {	"Doux Parfum",		Normal,		Ability_Status,		0, 1, 100, 0, 1, false,		0,None,		"Sweet Scent"	},	// Sweet Scent
  {	"Queue de Fer",		Acier,		Ability_Physical,	15, 100, 75, 0, 1, false,	0,None,		"Iron Tail"	},	// Iron Tail
  {	"Griff'Acier",		Acier,		Ability_Physical,	35, 50, 95, 0, 1, false,	0,None,		"Metal Claw"	},	// Metal Claw
  {	"Corps Perdu",		Combat,		Ability_Physical,	10, 70, 0, 0, 1, false,		0,None,		"Vital Throw"	},	// Vital Throw
  {	"Aurore",		Normal,		Ability_Status,		5, 0, 0, 0, 1, false,		0,None,		"Morning Sun"	},	// Morning Sun
  {	"Synthese",		Plante,		Ability_Status,		5, 0, 0, 0, 1, false,		0,None,		"Synthesis"	},	// Synthesis
  {	"Rayon Lune",		Normal,		Ability_Status,		5, 0, 0, 0, 1, false,		0,None,		"Monnlight"	},	// Monnlight
  {	"Puissance Cachee",	Normal,		Ability_Special,	15, 0, 100, 0, 1, false,	0,None,		"Hidden Power"	},	// Hidden Power
  {	"Coup Croix",		Combat,		Ability_Physical,	5, 100, 80, 2, 1, false,	0,None,		"Cross Chop"	},	// Cross Chop
  {	"Ouragan",		Dragon,		Ability_Special,	20, 40, 100, 0, 1, false,	0,None,		"Twister"	},	// Twister
  {	"Danse Pluie",		Eau,		Ability_Status,		5, 0, 0, 0, 1, false,		0,None,		"Rain Dance"	},	// Rain Dance
  {	"Zenith",		Feu,		Ability_Status,		5, 0, 0, 0, 1, false,		0,None,		"Sunny Day"	},	// Sunny Day
  {	"Machouille",		Tenebres,	Ability_Physical,	15, 80, 100, 0, 1, false,	0,None,		"Crunch"	},	// Crunch
  {	"Voile Miroir",		Psy,		Ability_Special,	20, 0, 100, 0, 1, false,	0,None,		"Mirror Coat"	},	// Mirror Coat
  {	"Boost",		Normal,		Ability_Status,		0, 0, 0, 0, 1, false,		0,None,		"Psych Up"	},	// Psych Up
  {	"Vitesse Extreme",	Normal,		Ability_Physical,	5, 80, 100, 0, 1, false,	0,None,		"Extreme Speed"	},	// Extreme Speed
  {	"Pouv. Antique",	Roche,		Ability_Special,	5, 60, 100, 0, 1, false,	0,None,		"Ancient Power"	},	// Ancient Power
  {	"Ball'Ombre",		Spectre,	Ability_Special,	15, 80, 100, 0, 1, false,	0,None,		"Shadow Ball"	},	// Shadow Ball
  {	"Prescience",		Psy,		Ability_Special,	15, 80, 100, 0, 1, false,	0,None,		"Future Sight"	},	// Future Sight
  {	"Eclate-Roc",		Combat,		Ability_Physical,	15, 20, 100, 0, 1, false,	0,None,		"Rock Smash"	},	// Rock Smash
  {	"Syphon",		Eau,		Ability_Special,	15, 15, 70, 0, 1, false,	0,None,		"Whirlpool"	},	// Whirlpool
  {	"Baston",		Tenebres,	Ability_Physical,	10, 10, 100, 0, 1, false,	0,None,		"Beat Up"	},	// Beat Up
};

const size_t pk_entries = sizeof(pokemons_db) / sizeof(pokemons_db[0]) - 2;
const size_t ab_entries = sizeof(abilities_db) / sizeof(abilities_db[0]) - 1;
