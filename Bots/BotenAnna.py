import discord

client = discord.Client()

@client.event
async def on_ready():
    print('We have logged in as {0.user}'.format(client))

@client.event
async def on_message(message):
    if message.author == client.user:
        return

    if message.content.startswith('$you dirty little slut'):
        await message.channel.send('be nice')

client.run('ODIxNTY0MTE0NTYzMzY2OTMy.YFFjNA.yezFo0nfDQJJYj3zWqU5HX_SJD0')
