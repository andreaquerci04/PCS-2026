#pragma once
#include <numeric>
template<typename I> 


class rational {
	I num_;
	I den_;
	int label_;
public:


/* gestione casi patologici   */
void update_status() {
      if (den_ == 0) {
            if (num_ == 0) 		label_ = 0 ;  /* NaN */
            else if (num_ > 0)  label_ = 1 ; /* +infinito */
            else 				label_ = -1;  /* -infinito */
        } else {
            label_ = 2;  /* valore regolare */
        }
    }

void update_number() {
		if (label_!=2) {
			num_ = label_;
}
}


/* costruttore di default */	
	rational()
		: num_(I{0}), den_(I{1})
	{update_status();}
	

/* costruttore user defined */	
	rational(const I& n, const I& d)
		: num_(n), den_(d)
		
	{update_status();}

	
/* semplificazione frazione*/
rational& simpl() {
	I mcd = std::gcd(num_ , den_);
		if (mcd != 0) {
			num_ = num_ / mcd;
			den_ = den_ / mcd;
			}
	return *this;		
		
	}
	
	
/* restituisono valori di num e den e status*/
	I num() const {return num_;}
	I den() const {return den_;}
	int status() const{return label_;}

/* incremento */
	rational& operator+=(const rational& raz) {
		
		if (label_ * raz.label_ ==1){
			num_ = label_;
			den_ = 0;
			}
		else {
		num_ = num_*raz.den_ + raz.num_*den_;
		den_ = den_*raz.den_ ;	}
		update_status();
		update_number();
		return this -> simpl();
		}
		
/* somma */
	rational operator+(const rational& other) const{
		rational ret = *this;
		ret += other;
		return ret;
	}


/* decremento */
	rational& operator-=(const rational& raz) {
		if (label_ * raz.label_ ==-1){   
			num_ = label_;
			den_ = 0;
			}
		else {
		num_ = num_*raz.den_ - raz.num_*den_;
		den_ = den_*raz.den_ ;	}
		update_status();
		update_number();
		return this -> simpl();
		}
		
/* sottrazione */
	rational operator-(const rational& other) const{
		rational ret = *this;
		ret -= other;
		return ret;
	}


/*    *=    */
	rational& operator*=(const rational& raz) {
		num_ = num_*raz.num_;
		den_ = den_*raz.den_ ;	
		update_status();
		update_number();
		return this -> simpl();
		}
		
/* moltiplicazione */
	rational operator*(const rational& other) const{
		rational ret = *this;
		ret *= other;
		return ret;
	}

/*    /=     */
	rational& operator/=(const rational& raz) {
		if (raz.label_ == 1 or raz.label_ == -1) { 
			num_ = 0;
			den_ = 0;
			}
		else if ((label_ == 1 || label_ == -1) && raz.num_ == 0)
		{num_ = 0;
			den_ = 0;}
		else{
		num_ = num_*raz.den_ ;
		den_ = den_*raz.num_ ;	}
		update_status();
		update_number();
		return this -> simpl();
		}
		
/* divisione */
	rational operator/(const rational& other) const{
		rational ret = *this;
		ret /= other;
		return ret;
	}



};



/* implementazione della stampa */
template <typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    return os << r.num() << "/" << r.den() << " " ;
}