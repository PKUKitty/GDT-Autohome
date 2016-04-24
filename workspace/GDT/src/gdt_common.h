/*************************************************************************
	> File Name: gdt_common.h
	> Author: YuJun
	> Mail: yujun@travelsky.com 
	> Created Time: Sun Apr 24 21:43:08 2016
 ************************************************************************/

#ifndef _GDT_COMMON_H
#define _GDT_COMMON_H
namespace gdt
{
    enum ServerRole{
        RECEIVER = 0,
        SENDER,
        BOTH
    };


    enum DataCommMode{
        ASYN = 0,
        SYN,
        OTHER
    };

    enum FileChangedAction{
        TRANSFER = 0,
        WRITEFILE,
        OTHER
    }
    
}

#endif
