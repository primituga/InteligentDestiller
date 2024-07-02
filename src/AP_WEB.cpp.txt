/*! \file AP_WEB.cpp */

#include "AP.h"			// Definitions
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
// bool wifi_Status;

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
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"started\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"startAction()\">Start</button>");

						/*======== STOP BUTTON ============*/
						if (header.indexOf("GET /stop") >= 0)
						{
							BTN_Stop = true;
							setTimer(OFF);
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"stoped\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"stopAction()\">Stop</button>");

						/*======== RESET BUTTON ============*/
						if (header.indexOf("GET /reset") >= 0)
						{
							BTN_Reset = true;
							resetTimer();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"stoped\"}"); // JSON response
						}
						client.println("<button class=\"button\" onclick=\"resetAction()\">Reset</button>");
						client.println("<p></p>");

						/*======== TIMER FUNCTION ============*/

						client.print("<blc id='content'>");
						/////////////////
						client.print("<blc> TIMER: ");
						client.print("<blc style=\"width:14px; height: 14px; -webkit-border-radius: 7px;");
                        client.print(" -moz-border-radius: 7px; border-radius: 7px;background: ");
						if (timerStatus() == ON)
						{
							client.print("lime");
						}
						else
						{
							client.print("black");
						}
						client.print(" ;\"> </blc> ");

						client.print("<span id=\"timer\">" + String(getTimerHour()) + ":" + String(getTimerMinute()) + ":" + String(getTimerSecound()) + "</span>");
						client.print("<script>");
						client.print("var timerStatus = " + String(timerStatus()) + ";"); // Get the timer status
						client.print("var timerElement = document.getElementById('timer');");
						client.print("var timerValue = timerElement.innerHTML.split(':');");
						client.print("var hour = parseInt(timerValue[0]);");
						client.print("var minute = parseInt(timerValue[1]);");
						client.print("var second = parseInt(timerValue[2]);");
						client.print("function updateTimer() {"); // Function to update the timer
						client.print("second--;");
						client.print("if (second < 0) {");
						client.print("second = 59;");
						client.print("minute--;");
						client.print("if (minute < 0) {");
						client.print("minute = 59;");
						client.print("hour--;");
						client.print("if (hour < 0) {");
						client.print("hour = 0;");
						client.print("minute = 0;");
						client.print("second = 0;");
						client.print("}");
						client.print("}");
						client.print("}");
						client.print("timerElement.innerHTML = hour.toString().padStart(2, '0') + ':' + minute.toString().padStart(2, '0') + ':' + second.toString().padStart(2, '0');");
						client.print("}");
						client.print("if (timerStatus == 1) {"); // Only update the timer if the status is ON
						client.print("setInterval(updateTimer, 1000);"); // Call the updateTimer function every second
						client.print("}");
						client.print("</script>");
						client.print(html_new_line);

						/*======== +1 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /add1s") >= 0)
						{
							BTN_Stop = true;
							add1s();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"add1sec\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"add1sAction()\">+ 1s</button>");

						/*======== +5 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /add5s") >= 0)
						{
							BTN_Stop = true;
							add5s();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"add5sec\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"add5sAction()\">+ 5s</button>");

						/*======== +10 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /add10s") >= 0)
						{
							BTN_Stop = true;
							add10s();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"add10sec\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"add10sAction()\">+ 10s</button>");

						/*======== +1 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /add1m") >= 0)
						{
							BTN_Stop = true;
							add1m();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"add1min\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"add1mAction()\">+ 1m</button>");

						/*======== +5 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /add5m") >= 0)
						{
							BTN_Stop = true;
							add5m();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"add5min\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"add5mAction()\">+ 5m</button>");

						/*======== +10 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /add10m") >= 0)
						{
							BTN_Stop = true;
							add10m();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"add10min\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"add10mAction()\">+ 10m</button>");
						client.println("<p></p>");

						/*======== -1 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /rem1s") >= 0)
						{
							BTN_Stop = true;
							rem1s();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"rem1sec\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"rem1sAction()\">- 1s</button>");

						/*======== -5 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /rem5s") >= 0)
						{
							BTN_Stop = true;
							rem5s();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"rem5sec\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"rem5sAction()\">- 5s</button>");

						/*======== -10 SECOUND  BUTTON ============*/
						if (header.indexOf("GET /rem10s") >= 0)
						{
							BTN_Stop = true;
							rem10s();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"rem10sec\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"rem10sAction()\">- 10s</button>");

						/*======== -1 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /rem1m") >= 0)
						{
							BTN_Stop = true;
							rem1m();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"rem1min\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"rem1mAction()\">- 1m</button>");

						/*======== -5 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /rem5m") >= 0)
						{
							BTN_Stop = true;
							rem5m();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"rem5min\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"rem5mAction()\">- 5m</button>");

						/*======== -10 MINUTE  BUTTON ============*/
						if (header.indexOf("GET /rem10m") >= 0)
						{
							BTN_Stop = true;
							rem10m();
							// Respond with a JSON object or a simple message
							client.println("HTTP/1.1 200 OK");
							client.println("Content-Type: application/json");
							client.println();							// End of headers
							client.println("{\"status\":\"rem10min\"}"); // JSON response
						}
						client.print("<button class=\"button\" onclick=\"rem10mAction()\">- 10m</button>");
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
						client.println("<blc><p><a href=\"/pump\"><button class=\"button\" onclick=\"updateStatus('/pump')\">Pump");
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
						//client.print(scriptAjax);
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