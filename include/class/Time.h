// -*- compile-command: "./compile.sh"; -*-
// Time.h
//
// last-edit-by: <>
//
// Description:
//
//////////////////////////////////////////////////////////////////////

#ifndef TIME_H
#define TIME_H 1

class Time{

 public:
  Time();
  Time(unsigned int);
  ~Time();

  friend bool operator ==(const Time&, const Time&);
  friend bool operator !=(const Time&, const Time&);
  friend bool operator <(const Time&, const Time&);
  friend bool operator >(const Time&, const Time&);
  friend bool operator >=(const Time&, const Time&);
  friend bool operator <=(const Time&, const Time&);

  friend Time operator +(const Time&, const Time&);
  void operator +=(const Time&);
  friend Time operator -(const Time&, const Time&);
  void operator -=(const Time&);
};


#endif // TIME_H
//////////////////////////////////////////////////////////////////////
// $Log:$
//
