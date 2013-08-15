/* 
 * File:   ClasseBase.h
 * Author: leandro
 *
 * Created on 4 de Agosto de 2012, 10:29
 */

#include <cstdio>

#ifndef CLASSEBASE_H
#define	CLASSEBASE_H


class ClasseBase {
public:
    ClasseBase();
    ClasseBase(const ClasseBase& orig);
    virtual ~ClasseBase();
    void base();
    
    
private:

};

#endif	/* CLASSEBASE_H */

