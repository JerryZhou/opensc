#include "pvar.h"

///
PVar::PVar()
{
}

///
PVar::~PVar()
{
}

///
operator PVar:: bool ()
{
    return this->Result();
}

/// !P : not 
bool PVar::Not(bool left)
{
    return !left;
}

/// P∧Q : and
bool PVar::Conjunction(bool left, bool right)
{
    return left && right;
}

/// P∨Q : or
bool PVar::Disjunction(bool left, bool right)
{
    return left || right;
}

/// P→Q = !P∨Q
bool PVar::Implication(bool left, bool right)
{
    return PVar::Disjunction(PVar::Not(left) , right);
}

/// (P→Q)∧(Q→P) = P\Q : !(xor)
bool PVar::Biconditional(bool left, bool right)
{
    return PVar::Conjunction(
	    PVar::Implication(left, right), 
	    PVar::Implication(right, left));
}

///
PVarCombination::PVarCombination(PropositionCombination c, PVar* l, PVar* r)
:left(l)
,right(r)
,combination(c)
{
}

///
PVarCombination::~PVarCombination()
{
}

///
bool PVarCombination::Result() const
{
    switch(c)
    {
	case PCombination_Not:
	    return PVar::Not(this->left->Result());
	    break;
	case PCombination_Conjunction:
	    return PVar::Conjunction(this->left->Result(), this->right->Result());
	    break;
	case PCombination_Disjunction:
	    return PVar::Disjunction(this->left->Result(), this->right->Result());
	    break;
	case PCombination_Implication:
	    return PVar::Implication(this->left->Result(), this->right->Result());
	    break;
	case PCombination_Biconditional:
	    return PVar::Biconditional(this->left->Result(), this->right->Result());
	    break;
	default:
	    assert(false);
    }
    return false;
}
