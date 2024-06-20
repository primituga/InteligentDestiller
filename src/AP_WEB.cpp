

/*! \file AP_WEB.cpp */

#include "MD.h"		 // Definitions
#include "AP_WebPage.h" // WebPage HTML content

// Auxiliar variables to store the current output state
String outputStartButton = "off";
String outputStopButton = "off";
String outputResetButton = "off";
char BTN_Start = false;
char BTN_Stop = false;
char BTN_Reset = false;
char BTN_add1s = false;
char BTN_add5s = false;
char BTN_add10s = false;
char BTN_add1m = false;
char BTN_add5m = false;
char BTN_add10m = false;
char BTN_rem1s = false;
char BTN_rem5s = false;
char BTN_rem10s = false;
char BTN_rem1m = false;
char BTN_rem5m = false;
char BTN_rem10m = false;
char BTN_auto = false;
char BTN_pump = false;
char BTN_dump_condensor = false;
char BTN_resistor = false;
char BTN_water_in = false;
//bool wifi_Status;

/*! \brief Definition of timeout limit                                  */
#define timeoutTime 1000

/*! \brief Declaration of server initialized on port 80 (HTTP)          */
// WiFiServer server(80);

/*! \fn void ProcessWebPage
	\brief Generates webclient and serves the HTML webpage
*/
void ProcessWebPage(void)
{
	WiFiClient client = isClientAvailable(); // Listen for incoming clients
	static unsigned long previousTime = 0;
	unsigned long currentTime = millis();
	static String header;

	if (client)
	{
		previousTime = currentTime;
		String currentLine = "";
		while (client.connected() && currentTime - previousTime <= timeoutTime)
		{
			currentTime = millis();
			if (client.available())
			{
				char c = client.read();
				header += c;
				if (c == '\n')
				{
					if (currentLine.length() == 0)
					{
						client.flush();
						client.println("HTTP/1.1 200 OK");
						client.println("Content-type:text/html");
						client.println("Connection: close");

						client.println(html_init);

						client.print(html_header);

						// WiFi STATUS
						client.print(html_wifi_init);
						if (WiFi.isConnected() == true)
							(client.print(html_Lime));
						else
							(client.print(html_Red));
						client.print(html_wifi_end);

						// IP STATUS
						client.print(html_circle_init);
						client.print(html_IP1);
						client.print(WiFi.localIP());
						client.print(html_IP2);
						client.print(html_circle_end);

						client.print(html_line);

						/************************************************************************/
						/* TIMER BLOCK                                                          */
						/************************************************************************/

						/*======== START BUTTON ============*/
						if (header.indexOf("GET /start") >= 0)
						{
							BTN_Start = true;
							setTimer(ON);
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<div><blc><p><a href=\"/start\"><button class=\"button\">Start</button></a></p></blc>");

						/*======== STOP BUTTON ============*/
						if (header.indexOf("GET /stop") >= 0)
						{
							BTN_Stop = true;
							setTimer(OFF);
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/stop\"><button class=\"button\">Stop</button></a></p></blc>");

						/*======== RESET BUTTON ============*/
						if (header.indexOf("GET /reset") >= 0)
						{
							BTN_Reset = true;
							resetTimer();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/reset\"><button class=\"button\">Reset</button></a></p></blc></div>");

						/*======== TIMER FUNCTION ============*/
						client.print(html_circle_init);
						client.print(html_Timer_init);
						client.print(html_indicator_init);
						if (timerStatus() == ON)
							(client.print(html_Lime));
						else
							(client.print(html_Black));
						client.print(html_indicator_end);
						client.print(html_Timer_end);
						client.print(getTimerHour());
						client.print(":");
						client.print(getTimerMinute());
						client.print(":");
						client.print(getTimerSecound());
						client.print(html_circle_end);

						client.print(html_new_line);

						/*======== +1 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /add1s") >= 0)
						{
							BTN_add1s = true;
							add1s();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/add1s\"><button class=\"button\">+ 1s</button></a></p></blc>");

						/*======== +5 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /add5s") >= 0)
						{
							BTN_add5s = true;
							add5s();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/add5s\"><button class=\"button\">+ 5s</button></a></p></blc>");

						/*======== +10 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /add10s") >= 0)
						{
							BTN_add10s = true;
							add10s();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/add10s\"><button class=\"button\">+ 10s</button></a></p></blc>");

						/*======== -1 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /rem1s") >= 0)
						{
							BTN_rem1s = true;
							rem1s();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/rem1s\"><button class=\"button\">- 1s</button></a></p></blc>");

						/*======== -5 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /rem5s") >= 0)
						{
							BTN_rem5s = true;
							rem5s();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/rem5s\"><button class=\"button\">- 5s</button></a></p></blc>");

						/*======== -10 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /rem10s") >= 0)
						{
							BTN_rem10s = true;
							rem10s();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/rem10s\"><button class=\"button\">- 10s</button></a></p></blc>");

						client.print(html_new_line);

						/*======== +1 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /add1m") >= 0)
						{
							BTN_add1m = true;
							add1m();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/add1m\"><button class=\"button\">+ 1m</button></a></p></blc>");

						/*======== +5 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /add5m") >= 0)
						{
							BTN_add5m = true;
							add5m();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/add5m\"><button class=\"button\">+ 5m</button></a></p></blc>");

						/*======== +10 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /add10m") >= 0)
						{
							BTN_add10m = true;
							add10m();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/add10m\"><button class=\"button\">+ 10m</button></a></p></blc>");

						/*======== -1 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /rem1m") >= 0)
						{
							BTN_rem1m = true;
							rem1m();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/rem1m\"><button class=\"button\">- 1m</button></a></p></blc>");

						/*======== -5 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /rem5m") >= 0)
						{
							BTN_rem5m = true;
							rem5m();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/rem5m\"><button class=\"button\">- 5m</button></a></p></blc>");

						/*======== -10 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /rem10m") >= 0)
						{
							BTN_rem10m = true;
							rem10m();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/rem10m\"><button class=\"button\">- 10m</button></a></p></blc>");
						client.print(html_line);

						/************************************************************************/
						/* SENSORS BLOCK                                                        */
						/************************************************************************/

						/*============= Auto BUTTON ================*/
						if (header.indexOf("GET /auto") >= 0)
						{
							BTN_auto = true;
							toggleAutoModeWEB();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
							BTN_auto = OFF;
						}
						client.println("<blc><p><a href=\"/auto\"><button class=\"button\">Auto");
						client.print(html_indicator_init);
						if (getAutoMode() == ON)
							(client.print(html_Lime));
						else
							(client.print(html_Black));
						client.print(html_indicator_end);
						client.println("</button></a></p></blc>");

						/*============= Pump BUTTON ================*/
						if (header.indexOf("GET /pump") >= 0)
						{
							BTN_pump = true;
							togglePump();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/pump\"><button class=\"button\">Pump");
						client.print(html_indicator_init);
						if (getPump() == ON)
							(client.print(html_Lime));
						else
							(client.print(html_Black));
						client.print(html_indicator_end);
						client.println("</button></a></p></blc>");

						/*============= Dump Condensor BUTTON ================*/
						if (header.indexOf("GET /DumpCondensor") >= 0)
						{
							BTN_dump_condensor = true;
							toggleValveWaterOut();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/DumpCondensor\"><button class=\"button\">Dump Condensor");
						client.print(html_indicator_init);
						if (getValv_Water_Out() == ON)
							(client.print(html_Lime));
						else
							(client.print(html_Black));
						client.print(html_indicator_end);
						client.println("</button></a></p></blc>");

						client.print(html_new_line);

						/*============= Resistor BUTTON ================*/
						if (header.indexOf("GET /resistor") >= 0)
						{
							BTN_resistor = true;
							toggleResistor();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/resistor\"><button class=\"button\">Resistor");
						client.print(html_indicator_init);
						if (getResistor() == ON)
							(client.print(html_Lime));
						else
							(client.print(html_Black));
						client.print(html_indicator_end);
						client.println("</button></a></p></blc>");

						/*============= Water IN BUTTON ================*/
						if (header.indexOf("GET /waterIn") >= 0)
						{
							BTN_water_in = true;
							toggleValveWaterIn();
							client.print("<HEAD>");
							client.print("<meta http-equiv=\"refresh\" content=\"0;url=/\">");
							client.print("</head>");
						}
						client.println("<blc><p><a href=\"/waterIn\"><button class=\"button\">Water In");
						client.print(html_indicator_init);
						if (getValv_Water_In() == ON)
							(client.print(html_Lime));
						else
							(client.print(html_Black));
						client.print(html_indicator_end);
						client.println("</button></a></p></blc>");

						/*============= Water Min Indicator ================*/
						client.print(html_circle_init);
						client.print(html_Water_Min_init);
						client.print(html_indicator_init);
						if (getWaterMin() == ON)
							(client.print(html_Red));
						else
							(client.print(html_Black));
						client.print(html_indicator_end);
						client.print(html_Water_Min_end);

						client.print(html_new_line);

						/*============= Alarm Indicator ================*/
						client.print(html_circle_init);
						client.print(html_Alarm_init);
						client.print(html_indicator_init);
						if (getAlarm() == ON)
							(client.print(html_Red));
						else
							(client.print(html_Black));
						client.print(html_indicator_end);
						client.print(html_Alarm_end);

						//////////////////////////
						client.print(html_closing);

						// The HTTP response ends with another blank line
						client.println();
						// Break out of the while loop
						break;
					}
					else
					{
						currentLine = "";
					}
				}
				else if (c != '\r')
				{
					currentLine += c;
				}
			}
		}
		// Clear the header variable
		header = "";
		// Close the connection
		client.stop();
	}
}