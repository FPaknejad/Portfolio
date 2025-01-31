import requests

# Define the API endpoint
url = "https://smmcity.com/api/v2"

# Define the headers
# headers = {
#     "Authorization": "Bearer YOUR_API_KEY",  # Replace with your actual API key/token if needed
#     "Content-Type": "application/json"       # Adjust the Content-Type as needed
# }

# Define the body or parameters
data = {
    "key": "574f904a4e78e3b8cf0d945262cb1def",
    "action" : "add",
    "service":"417",#twitch livestream views
    "link":"https://www.twitch.tv/niuklear",
    "quantity":"10"

 
    # "key": "574f904a4e78e3b8cf0d945262cb1def",
    # "action" : "add",
    # "service":"563",#twitch livestream views
    # "link":"https://kick.com/niuklear",
    # "quantity":"10"
    
}

# Make the POST request
response = requests.post(url, json=data)

# Check the response
if response.status_code == 200:
    print("Request was successful!")
    print("Response:", response.json())
else:
    print(f"Error {response.status_code}: {response.text}")
