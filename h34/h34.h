/*
 *	@file h34.h
 *  @author Your name goes here
 *  @version  what day and meeting time
 */
#ifndef H34_H_
#define H34_H_

#include <string>

/////// Declare all of your classes here ////////////////
/////// In this order: Worker, SalariedWorker, HourlyWorker
class Worker
{
	std::string name;
	double rate;
public:
	Worker(const std::string& name, double rate);
	virtual ~Worker() = default;
	// Add remaining members here . . .
};


#endif
