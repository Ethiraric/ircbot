/*
** Pokemon.h for  in /home/sabour_f/rendu/ircbot/AI/include
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue May 12 12:50:20 2015 Florian SABOURIN
** Last update Tue May 12 12:50:25 2015 Florian SABOURIN
*/

#ifndef POKEMON_H_
# define POKEMON_H_

# include <sys/types.h>
# include <stdbool.h>

# define None 0

typedef enum
{
  Normal = 1,
  Combat,
  Vol,
  Poison,
  Sol,
  Roche,
  Insecte,
  Spectre,
  Acier,
  Feu,
  Eau,
  Plante,
  Electric,
  Psy,
  Glace,
  Dragon,
  Tenebres,
  Inconnu
} e_type;

typedef enum
{
  Ability_None,
  Ability_Physical,
  Ability_Special,
  Ability_Status,
} e_abcateg;

typedef enum
{
  Status_BPSN,
  Status_PSN,
  Status_BRN,
  Status_SLP,
  Status_FRZ,
  Status_PAR,
  Status_FNT
} e_status;

typedef struct
{
    const char	*name;
    int		type;
    int		categ;
    int		PP;
    int		power;
    int		acc;
    int		crit;
    int		turn;
    bool	OHKO;
    int		prob;
    e_status	stat;
} t_ability;

typedef enum
  {
    EggGroup_Amorphous = 0x01,
    EggGroup_Bug = 0x02,
    EggGroup_Ditto = 0x04,
    EggGroup_Dragon = 0x08,
    EggGroup_Fairy = 0x10,
    EggGroup_Field = 0x20,
    EggGroup_Flying = 0x40,
    EggGroup_Grass = 0x80,
    EggGroup_Human_Like = 0x100,
    EggGroup_Mineral = 0x200,
    EggGroup_Monster = 0x400,
    EggGroup_Undiscovered = 0x800,
    EggGroup_Water1 = 0x1000,
    EggGroup_Water2 = 0x2000,
    EggGroup_Water3 = 0x4000
  } e_egggrp;

typedef enum
{
  Undefined,
  Fast,
  MediumFast,
  MediumSlow,
  Slow
} e_xpgrp;

typedef struct
{
    const char	*nom;
    int		pv;
    int		atk;
    int		def;
    int		atksp;
    int		defsp;
    int		speed;
    e_type	type1;
    e_type	type2;
    int		height;
    int		weight;
    int		catchr;
    int		gender;
    e_egggrp	egggrp;
    int		eggc;
    int		friendship;
    int		xp_yield;
    e_xpgrp	xpgrp;
    int		epv;
    int		eatk;
    int		edef;
    int		eatksp;
    int		edefsp;
    int		espeed;
    const char	*name;
} t_poke;

extern const t_poke	pokemons_db[];
extern const t_ability	abilities_db[];
extern const size_t pk_entries;
extern const size_t ab_entries;

#endif /* !POKEMON_H_ */
