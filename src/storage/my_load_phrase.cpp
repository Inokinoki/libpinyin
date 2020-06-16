/* 
 *  libpinyin
 *  Library to deal with pinyin.
 *  
 *  Copyright (C) 2020 Weixuan XIAO <veyx.shaw@gmail.com>
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "my_load_phrase.h"

int my_load_phrase(FILE *infile, char *phrase) {
    char temp;
    int length = 0;
    fscanf(infile, "%c", &temp);
    while (temp != '\t' && temp != ' ') {
        phrase[length] = temp;
        fscanf(infile, "%c", &temp);
        length++;
    }
    phrase[length] = '\0';
    return length;
}
