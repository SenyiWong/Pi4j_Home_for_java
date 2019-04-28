package com.wjj.home;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

import com.wjj.home.gpio.GpioBean;
import com.wjj.home.socket.NetSocket;

public class MainHomeDevice {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Thread t = Thread.currentThread();
		t.setName("MainHomeDevice");
		
		NetSocket net = new NetSocket(new GpioBean(),getIp());
		net.send(System.getProperty("user.name"));
	}
	
	private static String getIp(){
		String ip = "";
		try {
			File directory = new File("");//参数为空 
			String courseFile = directory.getCanonicalPath();
			String filepath = courseFile+"/resource/ip.txt";
			System.out.println(filepath);
			File file = new File(filepath);
			if (file.isFile() && file.exists()) { //判断文件是否存在
				InputStreamReader read = new InputStreamReader(new FileInputStream(file), "UTF-8");
				BufferedReader bufferedReader = new BufferedReader(read);
			    String lineTxt = null;
			    while ((lineTxt = bufferedReader.readLine()) != null) {
			    	ip = lineTxt;         
			    }       
			    read.close();
		    } else {
		        System.out.println("找不到指定的文件");
		    }
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}//考虑到编码格式
		return ip;
	}

}