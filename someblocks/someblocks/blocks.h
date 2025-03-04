//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"  ", "awk 'NR==1 {sub(/,/, \"\", $4); print $4}' <(acpi -V)",                5,      0},
	{"  ", "pactl get-sink-volume audio_effect.j293-convolver | awk '{print $5}'",  5,     0},
	{" ", "bluetoothctl devices Connected | awk '{$1=$2=\"\"; print $0}' | sed 's/^ *//'",    5,     0},
	{"󰍛 ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
	{"  ",  "awk 'NR==3 {print $3 \": \" $9}' <(ip -4 route); awk 'NR==1 {print $5 \": \" $9}' <(ip -4 route)",              5,             0},
	{" ", "date '+%b %d (%a) %I:%M%p'",					 5,		0},
	
	/* Updates whenever "pkill -SIGRTMIN+10 someblocks" is ran */
	/* {"", "date '+%b %d (%a) %I:%M%p'",					0,		10}, */
};



//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
