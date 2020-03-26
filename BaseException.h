#ifndef BaseException_h
#define BaseException_h
class BaseException
{
	protected : 
		char MessageErreur[50] ;
	public : 
		void setMessageErreur(const char*n) ;
		const char* getMessageErreur() const ;
		BaseException();
		BaseException(const char* iMess);
		~BaseException();
	
};

#endif
