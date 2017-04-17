package StudentPackage;

import java.util.Scanner;

public class StudentInfo
{
	String name;
	int roll;
	String class1;
	String address;
	int phone;
	String dob;
	String bloodgrp;
	public float internal1;
	public float internal2;
	public float internal3;
	public float internal4;
	public float internal5;
	public float external1;
	public float external2;
	public float external3;
	public float external4;
	public float external5;
	public StudentInfo()
	{
		name=" ";
		roll=0;
		class1=" ";
		address=" ";
		phone=0;
		dob=" ";
		bloodgrp=" ";
		internal1=0;
		internal2=0;
		internal3=0;
		internal4=0;
		internal5=0;
		external1=0;
		external2=0;
		external3=0;
		external4=0;
		external5=0;
		
	}
	public void EnterDetails()
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Name : ");
		name=s.next();
		System.out.println("Roll Number : ");
		roll=s.nextInt();
		System.out.println("Class : ");
		class1=s.next();
		System.out.println("Address : ");
		address=s.next();
		System.out.println("Phone Number : ");
		phone=s.nextInt();
		System.out.println("Date Of Birth : ");
		dob=s.next();
		System.out.println("Blood Group : ");
		bloodgrp=s.next();
		System.out.println("Enter Internal Marks Of The Student : ");
		System.out.println("ADS : ");
		internal1=s.nextFloat();
		System.out.println("MP : ");
		internal2=s.nextFloat();
		System.out.println("CG : ");
		internal3=s.nextFloat();
		System.out.println("M3 : ");
		internal4=s.nextFloat();
		System.out.println("PPL : ");
		internal5=s.nextFloat();
		System.out.println("Enter External Marks Of The Student : ");
		System.out.println("ADS : ");
		external1=s.nextFloat();
		System.out.println("MP : ");
		external2=s.nextFloat();
		System.out.println("CG : ");
		external3=s.nextFloat();
		System.out.println("M3 : ");
		external4=s.nextFloat();
		System.out.println("PPL : ");
		external5=s.nextFloat();
		
				
	}
	public void DisplayDetails()
	{
		System.out.println("The Details Of Entered Students Are As Follows : ");
		System.out.println("Name : "+name);
		System.out.println("Roll Number : "+roll);
		System.out.println("Class : "+class1);
		System.out.println("Address : "+address);
		System.out.println("Phone Number : "+phone);
		System.out.println("Date Of Birth : "+dob);
		System.out.println("Blood Group : "+bloodgrp);
		
	}
	public String getName() 
	{
		return name;
	}
	public void setName(String name) 
	{
		
		this.name = name;
	}
	public int getRoll() 
	{
		return roll;
	}
	public void setRoll(int roll) 
	{
		this.roll = roll;
	}
	public String getClass1() 
	{
		return class1;
	}
	public void setClass1(String class1) 
	{
		this.class1 = class1;
	}
	public String getAddress() 
	{
		return address;
	}
	public void setAddress(String address) 
	{
		this.address = address;
	}
	public int getPhone() 
	{
		return phone;
	}
	public void setPhone(int phone) 
	{
		this.phone = phone;
	}
	public String getDob() 
	{
		return dob;
	}
	public void setDob(String dob) 
	{
		this.dob = dob;
	}
	public String getBloodgrp() 
	{
		return bloodgrp;
	}
	public void setBloodgrp(String bloodgrp) 
	{
		this.bloodgrp = bloodgrp;
	}
	public float getInternal1() {
		return internal1;
	}
	public void setInternal1(float internal1) {
		this.internal1 = internal1;
	}
	public float getInternal2() {
		return internal2;
	}
	public void setInternal2(float internal2) {
		this.internal2 = internal2;
	}
	public float getInternal3() {
		return internal3;
	}
	public void setInternal3(float internal3) {
		this.internal3 = internal3;
	}
	public float getInternal4() {
		return internal4;
	}
	public void setInternal4(float internal4) {
		this.internal4 = internal4;
	}
	public float getInternal5() {
		return internal5;
	}
	public void setInternal5(float internal5) {
		this.internal5 = internal5;
	}
	public float getExternal1() {
		return external1;
	}
	public void setExternal1(float external1) {
		this.external1 = external1;
	}
	public float getExternal2() {
		return external2;
	}
	public void setExternal2(float external2) {
		this.external2 = external2;
	}
	public float getExternal3() {
		return external3;
	}
	public void setExternal3(float external3) {
		this.external3 = external3;
	}
	public float getExternal4() {
		return external4;
	}
	public void setExternal4(float external4) {
		this.external4 = external4;
	}
	public float getExternal5() {
		return external5;
	}
	public void setExternal5(float external5) {
		this.external5 = external5;
	}
	
	
	

}
