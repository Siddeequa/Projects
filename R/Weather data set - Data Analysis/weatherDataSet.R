#SIDDEEQUA JUMEEN
#TP056568


#load library needed to read dataset
library(readr)
#import dataset
HourlyWeather <- read_csv("C:/Users/User/Desktop/PFDA/PFDA Individual Assignment/HourlyweatherData.csv")
#view the dataset
View(HourlyWeather)


#install and load packages to be used
install.packages("dplyr") #for data manipulation
library(dplyr)
install.packages("ggplot2") #for data visualisation
library(ggplot2)
install.packages("extrafont") #to change font
library(extrafont)

#For better representation of graphs
theme_set(theme_classic())

#check fonts
fonts()


#Analysis
#Analysis 1
#understanding the dataset
head(HourlyWeather)
tail(HourlyWeather)
summary(HourlyWeather)


#Analysis 2
#checking for duplicate rows
which(duplicated(HourlyWeather))


#Analysis 3
#deleting missing wind direction values rows
newHourlyWeather <- HourlyWeather[complete.cases(HourlyWeather$wind_dir),] #new dataset created
summary(newHourlyWeather)


#Analysis 4
#deleting 'wind_gust' variable from new dataset
newHourlyWeather <- select(newHourlyWeather, -wind_gust)
summary(newHourlyWeather)


#Analysis 5
#average pressure per month at both locations
View(newHourlyWeather%>%group_by(origin,month)%>%summarise(avgPressure=mean(pressure, na.rm=TRUE)))


#Analysis 6
#average pressure per month for both locations combined
View(newHourlyWeather%>%group_by(month)%>%summarise(avgPressure=mean(pressure, na.rm=TRUE)))
#replacing pressure missing values with average pressure value
avgPressure <- mean(newHourlyWeather$pressure, na.rm=TRUE)
newHourlyWeather[is.na(newHourlyWeather)]=avgPressure
summary(newHourlyWeather)


#viewing new dataset to be analysed
View(newHourlyWeather) 


#Analysis 7
#number of observations per weather station
newHourlyWeather%>%
  ggplot(aes(x=origin))+
  geom_bar(color="black", fill="blue")+
  labs(title="Observations per weather station", 
       x="Weather Station", 
       y="Observations")+
  theme(axis.text=element_text(colour="black"), 
        plot.title=element_text(hjust=0.5), 
        text=element_text(family="Dubai"))


#Analysis 8
#temperature distribution
newHourlyWeather%>%
  ggplot(aes(x=temp))+
  geom_boxplot(color="black", fill="blue")+
  labs(title="Box Plot for Temperature",
       x="Temperature (F)")+
  theme(plot.title=element_text(hjust=0.5),
        text=element_text(family="Dubai"),
        axis.text=element_text(color="black"))+
  facet_wrap(~origin)


#Analysis 9
#dewpoint distribution
newHourlyWeather%>%
  ggplot(aes(x=dewp))+
  geom_boxplot(color="black", fill="blue")+
  labs(title="Box plot for dewpoint",
       x="Dewpoint (F)")+
  theme(plot.title=element_text(hjust=0.5),
        text=element_text(family="Dubai"))+
  facet_wrap(~origin)


#Analysis 10
#humidity distribution
newHourlyWeather%>%
  ggplot(aes(x=humid))+
  geom_histogram(color="black", fill="blue")+
  labs(title="Histogram showing humidity distribution",
       x="Relative Humidity",
       y="Observations")+
  theme(plot.title=element_text(hjust=0.5),
        text=element_text(family="Dubai"))+
  facet_wrap(~origin)


#Analysis 11
#wind direction distribution
newHourlyWeather%>%
  ggplot(aes(x=wind_dir))+
  geom_histogram(color="black", fill="blue")+
  labs(title="Histogram showing wind direction distribution",
       x="Wind direction (degrees)",
       y="Observations")+
  theme(plot.title=element_text(hjust=0.5),
        text=element_text(family="Dubai"))+
  facet_wrap(~origin)


#Analysis 12
#wind speed distribution
newHourlyWeather%>%
  ggplot(aes(x=wind_speed))+
  geom_histogram(color="black", fill="blue")+
  labs(title="Histogram showing wind speed distribution",
       x="Wind speed (mph)",
       y="Observations")+
  theme(plot.title=element_text(hjust=0.5),
        text=element_text(family="Dubai"))+
  facet_wrap(~origin)


#Analysis 13
#pressure distribution
newHourlyWeather%>%
  ggplot(aes(x=pressure))+
  geom_histogram(color="black", fill="blue")+
  labs(title="Histogram showing sea level pressure distribution",
       x="pressure (millibars)",
       y="Observations")+
  theme(plot.title=element_text(hjust=0.5),
        text=element_text(family="Dubai"))+
  facet_wrap(~origin)


#Analysis 14
#visibility distribution
newHourlyWeather%>%
  ggplot(aes(x=visib))+
  geom_histogram(color="black", fill="blue")+
  labs(title="Histogram showing visibility distribution",
       x="visibility (miles)",
       y="Observations")+
  theme(plot.title=element_text(hjust=0.5),
        text=element_text(family="Dubai"))+
  facet_wrap(~origin)


#Analysis 15
#temperature across the months
#creating average temperature per month table
AvgTempMonth <- newHourlyWeather%>%
  group_by(month)%>%
  summarise(avgtemp=mean(temp))
#generating graph
AvgTempMonth%>%
  ggplot(aes(x=month, y=avgtemp))+
  geom_line(aes(size=0.5), color="blue")+
  labs(title="Average temperature across the year",
       x="Months",
       y="Temperature (F)")+
  theme(axis.text=element_text(color="black"),
        plot.title=element_text(hjust=0.5),
        text=element_text(family="Dubai"))


#Analysis 16
#relationship between humidity and temperature
#creating average temperature and humidity per month table
AvgTempHumidMonth <- newHourlyWeather%>%
  group_by(month)%>%
  summarise(avgtemp=mean(temp), avgHumid=mean(humid))
#generating graph
AvgTempHumidMonth%>%
  ggplot(aes(x=avgtemp, y=avgHumid))+
  geom_line(aes(size=0.5), color="blue")+
  labs(title="Relationship between temperature and Relative Humidity",
       x="Temperature (F)",
       y="Relative Humidity")+
  theme(axis.text=element_text(color="black"),
        plot.title=element_text(hjust=0.5),
        text=element_text(family="Dubai"))
#creating average temperature and humidity per day table
AvgTempHumidDay <- newHourlyWeather%>%
  group_by(month)%>%
  summarise(avgtemp=mean(temp), avgHumid=mean(humid))
#generating graph
AvgTempHumidDay%>%
  ggplot(aes(x=avgtemp, y=avgHumid))+
  geom_line(aes(size=0.5), color="blue")+
  labs(title="Relationship between temperature and Relative Humidity",
       subtitle="Daily Average",
       x="Temperature (F)",
       y="Relative Humidity")+
  theme(axis.text=element_text(color="black"),
        plot.title=element_text(hjust=0.5),
        plot.subtitle=element_text(hjust=0.5),
        text=element_text(family="Dubai"))


#Analysis 17
#Relationship between dew point and time
#creating hourly average dew point table
HourlyDewp <- newHourlyWeather%>%
  group_by(hour)%>%
  summarise(avgDewp=mean(dewp))
#generating graph
HourlyDewp%>%
  ggplot(aes(x=hour, y=avgDewp))+
  geom_point(aes(size=0.5), color="blue")+
  labs(title="Relationship between time and dew point",
       x="Time (Hr)",
       y="Dew point (F")+
  theme(axis.text=element_text(color="black"),
        plot.title=element_text(hjust=0.5),
        plot.subtitle=element_text(hjust=0.5),
        text=element_text(family="Dubai"))


#Analysis 18
#Relationship between dew point and humidity
#creating daily average dew point and humidity table
DailyAvgDepAvgHumid <- newHourlyWeather%>%
  group_by(day)%>%
  summarise(avgDewp=mean(dewp), avgHumid=mean(humid))
#generating graph
DailyAvgDepAvgHumid%>%
  ggplot(aes(x=avgDewp, y=avgHumid))+
  geom_line(color="blue")+
  labs(title="Relationship between dew point and Relative Humidity",
       x="Dew point (F)",
       y="Relative Humidity")+
  theme(axis.text=element_text(color="black"),
        plot.title=element_text(hjust=0.5),
        plot.subtitle=element_text(hjust=0.5),
        text=element_text(family="Dubai"))


#Analysis 19
#relationship between visibility and wind speed
#creating daily average visibility and wind speed table
DailyVisibWSpeed <- newHourlyWeather%>%
  group_by(day)%>%
  summarise(avgVisib=mean(visib), avgWspeed=mean(wind_speed))
#generating graph
DailyVisibWSpeed%>%
  ggplot(aes(x=avgWspeed, y=avgVisib))+
  geom_line(color="blue")+
  labs(title="Relationship between visibility and wind speed",
       x="Wind speed (mph)",
       y="Visibility (miles)")+
  theme(axis.text=element_text(color="black"),
        plot.title=element_text(hjust=0.5),
        plot.subtitle=element_text(hjust=0.5),
        text=element_text(family="Dubai"))


#Analysis 20
#Precipitation over months
#creating monthly average precipitation table
MonthlyAvgPrecip <- newHourlyWeather%>%
  group_by(month, origin)%>%
  summarise(avgPrecip=mean(precip))
#generating graph
MonthlyAvgPrecip%>%
  ggplot(aes(x=month, y=avgPrecip))+
  geom_line(color="blue")+
  labs(title="Precipitation over months",
       x="Months",
       y="Precipitation (inches)")+
  theme(axis.text=element_text(color="black"),
        plot.title=element_text(hjust=0.5),
        plot.subtitle=element_text(hjust=0.5),
        text=element_text(family="Dubai"))+
  facet_wrap(~origin)


#Analysis 21
#Relationship between month and wind direction
#creating monthly average wind direction table
MonthlyWDir <- newHourlyWeather%>%
  group_by(month)%>%
  summarise(avgWDir=mean(wind_dir))
MonthlyWDir%>%
  ggplot(aes(x=month, y=avgWDir))+
  geom_line(color="blue")+
  labs(title="Wind direction over months",
       x="Months",
       y="Wind direction (Degrees)")+
  theme(axis.text=element_text(color="black"),
        plot.title=element_text(hjust=0.5),
        plot.subtitle=element_text(hjust=0.5),
        text=element_text(family="Dubai"))


#Additional feature
#Additional feature 6 (others in analysis section -explained in documentation)
#t-test comparing location and visibility
t.test(data=newHourlyWeather, visib~origin)







