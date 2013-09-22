#ifndef _PVAR_H_
#define _PVAR_H_

/// Proposition logic
///
class PVar
{
public:
    PVar();
    virtual ~PVar();

    virtual bool Result() const = 0;

    operator bool() const;

    static bool Not(bool b);
    static bool Conjunction(bool left, bool right);
    static bool Disjunction(bool left, bool right); 
    static bool Implication(bool left, bool right); 
    static bool Biconditional(bool left, bool right);

protected:
}

///
typedef enum 
{
    PCombination_Not,
    PCombination_Conjunction,
    PCombination_Disjunction,
    PCombination_Implication,
    PCombination_Biconditional,
}PropositionCombination;

///
class PVarCombination
{
public:
    PVarCombination(PropositionCombination c, PVar* left, PVar *right);
    virtual ~PVarCombination();

    virtual bool Result() const;

protected:
    PropositionCombination combination;
    PVar* left;
    PVar* right;
}

#endif
