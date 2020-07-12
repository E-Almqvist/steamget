#include <iostream>
#include "parameters.hpp"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace steamget {
	namespace lib {
		const std::string SteamURL = "http://api.steampowered.com/ISteamRemoteStorage/GetPublishedFileDetails/v1/"; // HTTP POST
		
		struct params { std::string fileid = "NONE"; std::string opath = "./"; };

		params getParameters() {
			params out;
			
			// get the arguments
			out.fileid = parameters::getArg('i');
			out.opath = parameters::getArg('o');

			return out;
		}

		cpr::Response sendHTTPPost( std::string url, cpr::Payload payload ) {
			cpr::Response r = cpr::Post(cpr::Url(url), payload);

			return r;	
		}

		json getAddonData( std::string id ) {
			json jsonRes = {}; // create a temporary buffer for the data
			json addonInfo = {};
			
			cpr::Payload payload = {  // create the payload to be sent to the steam api
				{"itemcount", "1"}, 
				{"publishedfileids[0]", id} 
			};
			
			std::cout << "Fetching addon information..." << std::endl;
			cpr::Response res = sendHTTPPost( SteamURL, payload ); // send the post request with the payload

			if( res.status_code == 200 ) { // if everything is fine, parse the json and download the addon

				// std::cout << "Success!" << std::endl << res.text << std::endl;
				jsonRes = json::parse(res.text);
				addonInfo = jsonRes["response"]["publishedfiledetails"][0];

				std::cout << addonInfo << std::endl;

				if( addonInfo["file_url"] == "" ) {
					
					// either the id is invalid or there is no such addon
					// or it is just empty
					std::cout << "Invalid or empty addon." << std::endl;
					exit(1);
				
				}

			} else if( res.status_code == 400) { // steam will respond with error 400 (bad request) if the id isn't valid.

				std::cout << "Invalid request! No such addon ID as '" << id << "'." << std::endl;
				exit(1);

			} else { // if something went wrong print out the status code and what steam sent

				std::cout << "Error! Something went wrong with the connection to the Steam servers." << std::endl << "Status: " << res.status_code << std::endl << "Text: " << res.text << std::endl;
				exit(1);

			}

			return addonInfo;
		
		}

		std::string downloadFileURL( std::string url ) { 
			std::cout << "Downloading files from Steam..." << std::endl;	
			return ""; 
		} 
	}

	void downloadAddon( lib::params target ) {
		
		// get the addon info first
		json data = lib::getAddonData( target.fileid );
		
		if( data["file_url"] != "" ) {	
		
			// download the file 
			lib::downloadFileURL( data["file_url"] );

			// extract the addon with gmad

		}

	}
}

int main( int argc, char** argv ) {
	parameters::init( argc, argv );	// pass the parameters
	steamget::lib::params P = steamget::lib::getParameters(); // get the parameters

	if( P.fileid != "" ) { // check if the id is not nothing
		
		steamget::downloadAddon( P ); // download the addon

	} else {
	
		std::cout << "You need to specify a ID!" << std::endl << "steamget -i {ID} -o {path=./}" << std::endl; 
	
	}
	return 0;
}
