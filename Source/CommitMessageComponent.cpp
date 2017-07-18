/*
  ==============================================================================

    CommitMessageComponent.cpp
    Created: 18 Jul 2017 12:57:00pm
    Author:  bvuong

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "CommitMessageComponent.h"

//==============================================================================
CommitMessageComponent::CommitMessageComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    commitMessageEditor = new TextEditor();
	commitMessageEditor->setFont(Font(20));
	commitMessageEditor->setMultiLine(true);
    commitMessageEditor->setReadOnly(true);
    addAndMakeVisible(commitMessageEditor);

	stringPool = new StringPool();
}

CommitMessageComponent::~CommitMessageComponent()
{
}

void CommitMessageComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("CommitMessageComponent", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void CommitMessageComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    commitMessageEditor->setBounds(getLocalBounds());
}

void CommitMessageComponent::generateMessage()
{
    // fetch from http://whatthecommit.com/
	StringRef startTag(stringPool->getPooledString("<p>"));
	StringRef endTag(stringPool->getPooledString("</p>"));
	ScopedPointer<URL> url = new URL("http://whatthecommit.com");
	String contentString = url->readEntireTextStream();
    commitMessageEditor->setText(contentString.substring(contentString.indexOf(startTag)+3, contentString.indexOf(endTag)).trim());
}
