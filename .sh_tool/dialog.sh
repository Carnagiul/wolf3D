#!/bin/bash

SURETY="$(osascript -e 'display dialog "Are you sure you want to partition this disk?" buttons {"Yes", "No"} default button "No"')"

if [ "$SURETY" = "button returned:Yes" ]; then
	echo "Yes, continue with partition."
else
	echo "No, cancel partition."
fi
