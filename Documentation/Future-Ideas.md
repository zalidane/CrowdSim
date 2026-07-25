# Future Ideas

## Agent Mood System

Each spawned person receives a random mood.

Possible moods:

- Happy
- Neutral
- Curious
- Angry
- Scared

Future systems may modify mood based on:

- Nearby people
- Crowding
- Reaching goals
- Time since last interaction

Potential ECS Components:

- Mood
- SocialNeed
- Energy

Potential Systems:

- MoodSystem
- SocialSystem
- CrowdBehaviorSystem