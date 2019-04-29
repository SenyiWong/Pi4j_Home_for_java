package com.wjj.home.socket;

public class NetGpioBean {
	private boolean highorlow;
	private String gpioName;
	private long deviceId;
	private String deviceName;
	private long time;
	
	public boolean getHighOrLow() {
		return highorlow;
	}
	public long getDeviceId() {
		return deviceId;
	}
	public String getDeviceName() {
		return deviceName;
	}
	
	public String getGpioName(){
		return gpioName;
	}
	
	public long getTime() {
		return time;
	}
}
