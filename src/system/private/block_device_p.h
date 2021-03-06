/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd
*
* Author:      maojj <maojunjie@uniontech.com>
* Maintainer:  maojj <maojunjie@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef BLOCK_DEVICE_P_H
#define BLOCK_DEVICE_P_H

#include <QSharedData>
#include <QDateTime>

namespace core {
namespace system {

class BlockDevice;

class BlockDevicePrivate : public QSharedData
{
public:
    BlockDevicePrivate()
        : QSharedData()
        , name {}
        , model {}
        , read_speed {0}
        , wirte_speed {0}
        , capacity {0}
        , blk_read {0}
        , bytes_read {0}
        , r_ps {.0}
        , rsec_ps {.0}
        , rrqm_ps {.0}
        , p_rrqm {.0}
        , p_util {.0}
        , tps {0}
        , blk_wrtn {0}
        , bytes_wrtn {0}
        , w_ps {.0}
        , wsec_ps {.0}
        , wrqm_ps {.0}
        , p_wrqm {.0}
        , read_iss {0}
        , write_com{0}
        , read_merged{0}
        , write_merged{0}
        , discard_sector{0}
        , _time_Sec{ QDateTime::currentSecsSinceEpoch() }
    {
    }
    BlockDevicePrivate(const BlockDevicePrivate &other)
        : QSharedData(other)
        , name(other.name)
        , model(other.model)
        , read_speed {other.read_speed}
        , wirte_speed {other.wirte_speed}
        , capacity(other.capacity)
        , blk_read(other.blk_read)
        , bytes_read(other.bytes_read)
        , r_ps(other.r_ps)
        , rsec_ps(other.rsec_ps)
        , rrqm_ps(other.rrqm_ps)
        , p_rrqm(other.p_rrqm)
        , p_util(other.p_util)
        , tps(other.tps)
        , blk_wrtn(other.blk_wrtn)
        , bytes_wrtn(other.bytes_wrtn)
        , w_ps(other.w_ps)
        , wsec_ps(other.wsec_ps)
        , wrqm_ps(other.wrqm_ps)
        , p_wrqm(other.p_wrqm)
        , read_iss {other.read_iss}
        , write_com{other.write_com}
        , read_merged{other.read_merged}
        , write_merged{other.write_merged}
        , discard_sector{other.discard_sector}
        , _time_Sec{other._time_Sec}
    {
    }

private:
    QByteArray name; // device name, eg: /dev/sda, /dev/loop0 ...
    QString model; // device model (might be vitual device)
    unsigned long long read_speed;  // ????????????
    unsigned long long wirte_speed; // ????????????
    unsigned long long capacity; // device capacity  ???????????????
    unsigned long long blk_read; // total number of blocks read ???????????????                       1
    unsigned long long bytes_read; // total number of bytes read?????????????????????*512
    double r_ps; // read requests completed per second 1  ??????????????? / ????????????                    1
    double rsec_ps; // sectors read per second  2?????????????????????????????????                            1
    double rrqm_ps; // read requests merged per second 3?????????????????????/ ????????????                   1
    double p_rrqm; // percentage of read requests merged together  4-?????????????????????/??????????????? % ?

    double p_util; // bandwidth utilization for the device 5- ??????   ?
    unsigned long long tps; // transfers per second ?????????????????? + ???????????????
    unsigned long long blk_wrtn; // total number of blocks written  ???????????????                   1
    unsigned long long bytes_wrtn; // total number of bytes read ??????????????? *512
    double w_ps; // write requests completed per second ???????????????/????????????
    double wsec_ps; // sectors written per second ???????????????/????????????
    double wrqm_ps; // write requests merged per second ?????????????????????/????????????
    double p_wrqm; // percentage of write requests merged together ?????????????????????/??????????????? % ?

    unsigned long long read_iss; // ???????????????
    unsigned long long write_com; // ???????????????
    unsigned long long read_merged; // ?????????????????????
    unsigned long long write_merged; // ?????????????????????
    quint64            discard_sector; // ???????????????

    qint64 _time_Sec;   //???????????????

    friend class BlockDevice;
};

} // namespace system
} // namespace core

#endif // BLOCK_DEVICE_P_H
