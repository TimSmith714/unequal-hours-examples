// See https://aka.ms/new-console-template for more information
Console.WriteLine("Hello, World!");

var sunRise = new DateTime(2022, 08, 11, 05, 42, 00);
var sunSet = new DateTime(2022, 08, 11, 20, 30, 00);
// Current Time
var currentTime = new DateTime(2022, 08, 11, 12, 00, 00);

var unequalNow = unequalTime(sunRise, sunSet, currentTime);


System.Console.WriteLine("Current Time: {0}, Unequal Time: {1}", currentTime.ToString(), unequalNow.ToString());

System.Console.WriteLine("Attempting a loop");
System.Console.WriteLine("============");

// Go through time
for (int hour = 6; hour < 20; hour++)
{
    currentTime = new DateTime(2022, 08, 11, hour, 0, 0);
    unequalNow = unequalTime(sunRise, sunSet, currentTime);
    System.Console.WriteLine("Current Time: {0}, Unequal Time: {1}", currentTime.ToString(), unequalNow.ToString());
}



// Function to calculate Unequal Time
DateTime unequalTime(DateTime sunrise, DateTime sunset, DateTime currentTime)
{
    // The number of seconds in 12 hours
    float unequalSeconds = 43200;
    var unequalTime = new DateTime();

    // TODO
    // Need to work out whether the time is before sunrise or after sunset as the logic will be different.
    if (currentTime < sunRise)
    {
        // Work out preSunrise time
    }
    else if (currentTime > sunSet)
    {
        // Work out post sunSet time
    }
    else
    {
        // during the day logic
        var daySeconds = System.Math.Abs((sunSet - sunRise).TotalSeconds);
        // Seconds elapsed in day
        var dayElapsedSeconds = System.Math.Abs((currentTime - sunRise).TotalSeconds);
        // Percentage of day elapsed
        double pcDay = dayElapsedSeconds / daySeconds;
        var unequalSecondsElapsed = System.Math.Abs(unequalSeconds / pcDay);
        //
        unequalTime = new DateTime(2022, 08, 11, 06, 00, 00).AddSeconds(unequalSecondsElapsed);

    }

    return unequalTime;

}