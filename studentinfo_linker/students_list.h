/*********************************************************************************
 *      Copyright:  (C) 2016 SCUEC
 *                  All rights reserved.
 *
 *       Filename:  students_list.h
 *    Description:  
 *                 
 *        Version:  1.0.0(11/2/2016)
 *         Author:  LI WJNG <liwjng@gmail.com>
 *      ChangeLog:  1, Release initial version on "11/2/2016 17:35:31 PM"
 *                 
 ********************************************************************************/

#ifndef  _STUDENTS_LIST_H_
#define  _STUDENTS_LIST_H_

#define NAME_LEN         32

enum{ male, female };

typedef struct student_s 
{
    char                   name[NAME_LEN];
    int                    gender;
    unsigned char          age;
    float                  score;
} student_t;  /* ---  end of struct student_s  ---*/ 


#endif   /* ----- #ifndef _STUDENTS_LIST_H_  ----- */

