/* 
 *  libpinyin
 *  Library to deal with pinyin.
 *  
 *  Copyright (C) 2013 Peng Wu <alexepico@gmail.com>
 *  
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 * 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef TABLE_INFO_H
#define TABLE_INFO_H

namespace pinyin{

class UserTableInfo;

class SystemTableInfo{
    friend class UserTableInfo;
private:
    int m_binary_format_version;
    int m_model_data_version;
    gfloat m_lambda;

    pinyin_table_info_t m_table_info[PHRASE_INDEX_LIBRARY_COUNT];

private:
    void reset();

    void postfix_tables();

public:
    SystemTableInfo();

    ~SystemTableInfo();

    bool load(const char * filename);

    pinyin_table_info_t * get_table_info();

    gfloat get_lambda();
};

class UserTableInfo{
private:
    int m_binary_format_version;
    int m_model_data_version;

public:
    UserTableInfo();

    bool load(const char * filename);

    bool save(const char * filename);

    bool is_conform(const SystemTableInfo * sysinfo);

    bool make_conform(const SystemTableInfo * sysinfo);
};

};


#endif
