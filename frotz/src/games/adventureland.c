/* 
Copyright (C) 2018 Microsoft Corporation

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <string.h>
#include "frotz.h"
#include "games.h"
#include "frotz_interface.h"

// Adventureland: http://ifdb.tads.org/viewgame?id=dy4ok8sdlut6ddj7

char** adventureland_intro_actions(int *n) {
  *n = 0;
  return NULL;
}

char* adventureland_clean_observation(char* obs) {
  char* pch;
  pch = strchr(obs, '>');
  if (pch != NULL) {
    *(pch-2) = '\0';
  }
  return obs+1;
}

int adventureland_victory() {
  char *death_text = "****  You have won  ****";
  if (strstr(world, death_text)) {
    return 1;
  }
  return 0;
}

int adventureland_game_over() {
  char *death_text = "*** You have died ***";
  if (strstr(world, death_text)) {
    return 1;
  }
  return 0;
}

int adventureland_get_self_object_num() {
  return 20;
}

int adventureland_get_moves() {
  return (((short) zmp[5320]) << 8) | zmp[5321]; // Also 5331
}

int adventureland_get_score() {
  return zmp[5319]; // Also 5329, 5345
}

int adventureland_max_score() {
  return 100;
}

int adventureland_get_num_world_objs() {
  return 106;
}

int adventureland_ignore_moved_obj(zword obj_num, zword dest_num) {
  return 0;
}

int adventureland_ignore_attr_diff(zword obj_num, zword attr_idx) {
  if (attr_idx == 2 || attr_idx == 25)
    return 1;
  return 0;
}

int adventureland_ignore_attr_clr(zword obj_num, zword attr_idx) {
  if (attr_idx == 2 || attr_idx == 25)
    return 1;
  return 0;
}
