#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "index_htm.h"

const char * WIFISSID = "ESP8266 5.05 jailbreak server";

AsyncWebServer server(80);

void setup(void) {
  Serial.begin( 115200 );
  Serial.println();
  Serial.println();
  pinMode( BUILTIN_LED, OUTPUT );
  digitalWrite( BUILTIN_LED, LOW );

  WiFi.mode( WIFI_AP );
  WiFi.softAP( WIFISSID );

  Serial.printf( "1. Connect your PS4 to '%s' access point.\n", WIFISSID );

  static const char * HTML_HEADER = "text/html";

  server.on( "/", HTTP_GET, [] ( AsyncWebServerRequest * request )
  {
    AsyncWebServerResponse *response = request->beginResponse_P( 200, HTML_HEADER, index_htm, index_htm_len );
    request->send(response);
  });

  server.onNotFound( []( AsyncWebServerRequest * request )
  {
    Serial.printf( "Not found http://%s%s\n", request->host().c_str(), request->url().c_str());
    request->send( 404 );
  });
  DefaultHeaders::Instance().addHeader( "Access-Control-Allow-Origin", "*" );
  server.begin();

  Serial.print( "2. Browse to '" );
  Serial.print( WiFi.softAPIP().toString()  );
  Serial.println( "' to jailbreak your PS4." );

  digitalWrite( BUILTIN_LED, HIGH );
}

void loop(void)
{
  delay(1000);
}

